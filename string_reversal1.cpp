#include <iostream>
#include <string>
using namespace std;
bool isAlphabet(char x){
	return ((x>='a' && x<='z') || (x>='A' && x<='Z'));
}
void reverse(string str){
	int l=0;
	int r=str.length()-1;
	while(l<r){
		if(!isAlphabet(str[l]))
			l++;
		else if(!isAlphabet(str[r]))
			r--;
		else{
			char temp=str[l];
			str[l]=str[r];
			str[r]=temp;
			l++;
			r--;
		}
	}
	cout<<"Output string: ";
	for(int i=0;i<str.length();i++){
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
