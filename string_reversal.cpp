#include <iostream>
#include <string>
using namespace std;
void reverse(string str){
	char temp[str.length()];
	int x=0;
	for(int i=str.length()-1;i>=0;i--){
		if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
			temp[x++]=str[i];
		}
	}
	int k=0;
	for(int i=0;i<str.length();i++){
		if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
			cout<<temp[k];
			k++;
		}
		else
			cout<<str[i];
	}
	cout<<endl;
}
int main(){
	char str[] = "a!!!b.c.d,e'f,ghi";
        cout << "Input string: " << str << endl;
        reverse(str);
        return 0;
}
