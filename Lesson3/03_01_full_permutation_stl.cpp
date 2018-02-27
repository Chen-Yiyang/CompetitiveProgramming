#include <bits/stdc++.h>
using namespace std;

stack<int> seq;
int seqNum,seqValues[1001];
bool numUsed[1001];

void _print()
{
	int i;
	
	// pop the stack values into an array for print
	for (i=seqNum;i>=1;i--){
		seqValues[i] = seq.top();
		seq.pop();
	}
	
	// push it back
	for (i=1;i<=seqNum;i++)
	{
		cout<<seqValues[i]<<' ';
		seq.push(seqValues[i]);
	}
	cout<<'\n';
	
	memset(seqValues,false,sizeof(seqValues));
	
	return ;
}


void dfs(){

	if (seq.size()==seqNum){		// one permuatation finished
		_print();
		return ;
	}
	
	int i;
	
	for (i=1;i<=seqNum;i++){
		
		if (numUsed[i])	// num in sequence alr
			continue;
		
		seq.push(i);
		numUsed[i] = true;
		
		dfs();
		
		seq.pop();
		numUsed[i] = false;
	}
	
	return ;
}

int main(){
	
	// initialisation
	cin>>seqNum;
	memset(numUsed,false,sizeof(numUsed));
	
	dfs();
	
	return 0;
}
