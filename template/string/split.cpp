/**
 * 描述： 模拟java，js等的字符串 split方法
 * 如：  "hello world" ->> ["hello","world"]
 * 传入需要分割的字符串，默认以空格分割，也可以传入一个字符作为指定的分隔符
 */
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string str){
    int strLen = str.size();
    vector<string> array;
    for(int i=0,j=0;i<strLen;){
        // isalpha(ch) 判断这个字符是否是一个字母
        while(isalpha(str[i])){
            ++i;
        }
        if(i!=j) array.push_back(str.substr(j,i-j));
        ++i;
        j=i;
    }
    return array;
}

// 能够指定分隔符
vector<string> split(string str, char ch){
    int strLen = str.size();
    vector<string> array;
    for(int i=0,j=0;i<strLen;){
        // isalpha(ch) 判断这个字符是否是一个字母
        while(i<strLen&&ch!=str[i]){
            ++i;
        }
        if(i!=j) array.push_back(str.substr(j,i-j));
        ++i;
        j=i;
    }
    return array;
}

int main(){
    string str = "hello world";
    vector<string> strArray = split(str);
    for(string theStr : strArray){
        cout<<theStr<<" ";
    }
    cout<<endl;
    string myString = "Bob,hit,a,ball,the,hit,BALL,flew,far,after,it,was,hit";
    vector<string> stringArray = split(myString,',');
    for(string theStr : stringArray){
        cout<<theStr<<" ";
    }
    cout<<endl;
    return 0;
}


