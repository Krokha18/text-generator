#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define BOOST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const char* delimiters=" ,.?!:;-()";
int matrix_word_to_delim[30000][1000];
bool is_delimiter(char c){
    if(strchr(delimiters,c)) return true;
    else return false;
}
bool the_end_of_sentence(string str){
    if(str.find('.')!=string::npos) return true;
    if(str.find('!')!=string::npos) return true;
    if(str.find('?')!=string::npos) return true;
    if(str.find('\n')!=string::npos) return true;
    if(str.find('\t')!=string::npos) return true;
    return false;
}
int main(){
    system("ls dataset/*>bookslist.txt");
    freopen("bookslist.txt","r",stdin);
    int i,j,count_books=0;
    int** matrix_word_to_word=new int*[30000];
    for(i=0;i<30000;i++) matrix_word_to_word[i]=new int[30000];
    char c;
    fseek(stdin,0,SEEK_SET);
    while(!feof(stdin)){
        c=getchar();
        if(c=='\n') count_books++;
    }
    char** booknames=new char*[count_books];
    fseek(stdin,0,SEEK_SET);
    for(i=0;i<count_books;i++){
        booknames[i]=new char[50];
        scanf("%s\n",booknames[i]);
    }
    int count_words=0;
    unordered_map<string,int> m;
    string* m2=new string[30000];
    int count_delim=0;
    unordered_map<string,int> m_delim;
    string* m2_delim=new string[1000];
    random_device rd;
    mt19937 mersenne(rd());
    shuffle(booknames,booknames+count_books,mersenne);
    BOOST;
    for(i=0;i<count_books;i++){
        freopen(booknames[i],"r",stdin);
        fseek(stdin,0,SEEK_SET);
        string word1("");
        string delim("");
        string word2("");
        bool t=false;
        while(!feof(stdin)){
            while(is_delimiter(c)){
                if(t) delim+=c;
                c=getchar();
            }
            t=true;
            if(!delim.empty()){
                int temp_delim;
                if(m_delim.find(delim)!=m_delim.end()) temp_delim=m_delim[delim];
                int temp2;
                if(!word2.empty())temp2=m[word2];
                if(m_delim.find(delim)==m.end()&&count_delim<1000) {
                    m_delim.insert(make_pair(delim,count_delim));
                    m2_delim[count_delim]=delim;
                    count_delim++;
                }
                else {if(m_delim.find(word2)!=m_delim.end()) matrix_word_to_delim[temp2][temp_delim]++;}
            }
            while(isalpha(c)||c=='\''){
                if(the_end_of_sentence(delim)) word1+=tolower(c);
                else word1+=c;
                c=getchar();
            }
            if(!word1.empty()){
                int temp1;
                if(m.find(word1)!=m.end()) temp1=m[word1];
                int temp_delim;
                if(!delim.empty()) temp_delim=m_delim[delim];
                int temp2;
                if(!word2.empty()) temp2=m[word2];
                if(m.find(word1)==m.end()&&count_words<30000){
                    m.insert(make_pair(word1,count_words));
                    m2[count_words]=word1;
                    temp1=count_words;
                    matrix_word_to_word[temp2][temp1]++;
                    count_words++;
                }
                else{ if(m.find(word1)!=m.end()) matrix_word_to_word[temp2][temp1]++;}
                word2=word1;
                word1.erase();
                delim.erase();
            }
            c=getchar();
        }
    }
    fcloseall();
    cout<<count_words<<endl;
    int start=mersenne()%count_words;
    cout<<m2[start];
    string next;
    string del;
    for(i=0;i<100;i++){
        discrete_distribution<> dis_delim(matrix_word_to_delim[start],matrix_word_to_delim[start]+count_delim);
        discrete_distribution<> dis_word(matrix_word_to_word[start],matrix_word_to_word[start]+count_words);
        start=dis_word(mersenne);
        del=m2_delim[dis_delim(mersenne)];
        next=m2[start];
        cout<<del<<next;
    }
    cout<<endl;
    return 0;
}
