#include<iostream>
using namespace std;
int ans[1500];
int main(){
	int begin,end;
	cin>>begin>>end;
	int cnt=0;
	for(int i=begin;i<=end;i++){
		if((i%4==0&&i%100!=0)||i%400==0){
			ans[cnt++]=i;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}