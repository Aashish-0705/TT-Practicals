#include <iostream>
#include <string>

using namespace std;

int main() {
    string paragraph,oldWord,newWord;
cout<<"Enter your paragraph:";
getline(cin,paragraph);
cout<<"Enter the word which you want to replace:";
cin>>oldWord;
cout<<"Enter the word which you want to replace it with:";
cin>>newWord;
    size_t pos = paragraph.find(oldWord);
    paragraph.replace(pos, oldWord.length(), newWord);
    cout << paragraph << endl;
    return 0;
}

