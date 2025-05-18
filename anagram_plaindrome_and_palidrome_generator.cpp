#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void Anagram_check(){
    string word1,word2;
    cin.ignore();
    cout<<"Enter the word: ";
    getline(cin,word1);

    cout<<"Enter the second word to check if it's anagram with the first word: ";
    getline(cin,word2);

    bool is_anagram,is_found1;
    if( word1.length()==word2.length()){
        for( int i = 0 ;i < word1.length() ; i++){
            for( int j = 0 ; j < word2.length() ; j++){
                bool is_found2=false;
                if( word1[i]==word2[j]){
                    is_found2=true;
                    is_found1=is_found2;
                    break;
                }
                is_found1=is_found2;
            }
        }
        if(is_found1){
            is_anagram=true;
        }
        else{
            is_anagram=false;
        }
    }

    else{
        is_anagram=false;
    }

    if ( is_anagram ){
        cout<<word1<<" and "<<word2<<": are anagram.";
    }

    else{
        cout<<word1<<" and "<<word2<<": are not anagram.";
    }

}

void Palindrome_check(){
    string sentence;

    cin.ignore();
    cout << "Enter a sentence: ";
    getline( cin , sentence);

    for( int i = 0 ; i < sentence.length() ; i++ ){
        if( (sentence[i] >= 'a' && sentence[i] <= 'z' ) || (sentence[i] >= 'A' && sentence[i] <= 'Z') ){
            sentence[i]=tolower(sentence[i]);
        }
    }

    string reverse;

    for( int i = sentence.length() - 1 ; i >= 0 ; i-- ){
        reverse.push_back(sentence[i]);
    }

    if ( reverse == sentence ){
        cout<<sentence<<": is palindrome.";
    }

    else{
        cout<<sentence<<": is not palindrome.";
    }
}

void Palindrome_generate(){
    int range;
    cout << "Enter a range: ";
    cin >> range;

    // Step 1: Build printable ASCII characters
    char chars[95];
    int count = 0;
    for (char c = 32; c <= 126; c++) {
        chars[count++] = c;
    }

    long long total = 1;
    for (int i = 0; i < range; i++) {
        total *= 95; // total combinations = 95^range
    }

    // Step 2: Generate all combinations iteratively
    for (long long i = 0; i < total; i++) {
        long long temp = i;
        string combination = "";

        for (int j = 0; j < range; j++) {
            combination = chars[temp % 95] + combination;
            temp /= 95;
        }
        string reverse;
        for(int k=combination.length()-1;k>=0;k--){
            reverse.push_back(combination[k]);
        }
        if(reverse==combination){
            cout << combination << endl;
        } 
    }
}

int main(){
    int option;
    
        cout<<"Welcome to anagram checker, paliondrom checker and  palindrome generator using ASCII values. Please choose what you want: "<<endl;
        cout<<"1.Anagram Check."<<endl;
        cout<<"2.Palindrome Check."<<endl;
        cout<<"3.Palindrome genereate using ASCII value."<<endl;
        cout<<"0.To exit."<<endl;

        cin>>option;

        if(option==1){
            Anagram_check();
        }

        else if(option==2){
            Palindrome_check();
        }

        else if(option==3){
            Palindrome_generate();
        }

        else if(option==0){

        }
        else{
            cout<<"Invalid Input.";
            return 1;
        }
    return 0;
}