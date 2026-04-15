#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXWORDS = 100;

struct WordPair
{
    string eng;
    string kor;
};

class MyDic
{
    WordPair words[MAXWORDS];
    int nWords;

    public:

    MyDic()
    {
        nWords = 0;
    }

    void add(string eng, string kor)
    {
        if(nWords >= MAXWORDS)
        {
            cout << "단어를 추가할 수 없습니다.\n";
            return;
        }

        words[nWords].eng = eng;
        words[nWords].kor = kor;
        nWords++;
    }


    void load(string filename)
    {
         ifstream fin(filename);

        if(!fin)
         {
            cout << "파일을 열 수 없습니다." << filename << endl;
            return;
         }

    nWords = 0;

     string eng, kor;
       while (fin >> eng >>kor)
      {
        add(eng,kor);
      }
       fin.close();
    }

    void store(string filename)
    {
        ofstream fout(filename);

        if(!fout)
        {
            cout << "파일을 저장 할 수 없습니다: " << filename << endl;
            return;
        }

        for (int i = 0; i <nWords; i++)
        {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
            fout.close();
    }

    void print()
    {
        cout << "===== 단어장 출력 =====\n";
        for (int i = 0; i < nWords; i++)
        {
            cout << i << " : " << words[i].eng << " - " << words[i].kor << endl;
        }
    }

        string getKor(int id)
    {
        if(id < 0 || id >= nWords)
        {
            return "잘못된 ID입니다.";
        }
        return words[id].kor;
    }

            string getEng(int id)
    {
        if(id < 0 || id >= nWords)
        {
            return "잘못된 ID입니다.";
        }
        return words[id].eng;
    }
};

int main()
{
    MyDic dic;

   dic.add("apple", "사과");
   dic.add("banana", "바나나");
   dic.add("book", "책");

   dic.print();

   cout << endl;
   cout << "1번 영어 단어 : " << dic.getEng(1) << endl;
   cout << "1번 한국어 단어 : " << dic.getKor(1) << endl;

   dic.store("dic.txt");

   cout << "\n파일 저장 후 다시 불러오기\n";

   MyDic dic2;
   dic2.load("dic.txt");
   dic2.print();

   return 0;
}