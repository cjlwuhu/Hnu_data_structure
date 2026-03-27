#include<bits/stdc++.h>
using namespace std;

stack<int> number;
stack<char> op;
char c,t;
int n;
string equ;
int count;
map<char , int> py;

char cal(char t){
	op.pop();
	
	int n1,n2;
	
	n1=number.top();
	number.pop();
	n2=number.top();
	number.pop();
	
	if(t=='-'){
		n2-=n1;
		number.push(n2);
	}
	else if(t=='+'){
		n2+=n1;
		number.push(n2);
	}
	else if(t=='*'){
		n2*=n1;
		number.push(n2);
	}
	else if(t=='/'){
		n2/=n1;
		number.push(n2);
	}
	
	return op.top();
}

int main(){
	py['/'] = 2;
	py['*'] = 2;
	py['-'] = 1;
	py['+'] = 1;
	py['#'] = -2; 
	
	cin>>equ;
	
	op.push('#');
	if(equ[0] <'0' || equ[0] >'9' ){
		cout<<"NO";
		return 0;
	}
	for(int i=0 ; i<equ.size() ; i++){
		c=equ[i];
		if(c>='0' && c<='9') {
			int j=i;
			int num=c-'0';
			while(equ[j+1]>='0' && equ[j+1]<='9'){
				num = num*10+(equ[j+1]-'0');
				j++;
			}
			i=j;
			number.push(num);
		}
		else if(c=='('){
			op.push('(');
		}
		else if(c==')'){
			t=op.top();
			while(t != '('){
				t=cal(t);
			}
			op.pop();
		}
		else if(c=='+' || c=='-' || c=='*' || c=='/' ){
			if(py[c] > py[op.top()]) op.push(c);
			else{
				char t = op.top();
				while(py[t] >= py[c]){
					t=cal(t);
					
				}
				op.push(c);
			}
		}
		else if(c=='#'){
			t=op.top();
			while(t != '#'){
				t=cal(t);
			}
		}
		else{
			cout<<"NO";
			return 0;
		}
	}
	
	cout<<number.top();
	return 0;
} 

//55+(3+4*5)-8/8+6+10*3#
//1+2*3-4+5#

