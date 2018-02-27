#include <bits/stdc++.h>
using namespace std;

const int SIZE = 8;		// size of the board = 8
int qCol[9];			// array storing the columns of the queens
int sum;				// to recors the total no. of different ways

bool checkCol(int qRow, int col){	// no. of queens placed & the column to be checked

	int i;
	
	for (i=1;i<qRow;i++){			// only examine the first qRow queens placed
		if (qCol[i]==col)
			return false;
	}
	
	return true;
}

bool checkDgnl(int qRow, int col){	// no. of queens placed (i.e. the row) & the column to be checked

	int i;
	
	for (i=1;i<qRow;i++){
		if ( abs(qCol[i]-col) == abs(i-qRow) )
			return false;
	}
	
	return true;
}

void _print(){
	
	int i,j;
	
	for (i=1;i<=SIZE;i++){
		for (j=1;j<=SIZE;j++){
			if (j==qCol[i])
				cout<<"*";
			else
				cout<<"0";
		}
		cout<<"\n";
	}
	
	cout<<"\n";
	sum++;
	
	return ;
}

void dfs(int qRow){			// pass the row as the parameter for recursion
	
	if (qRow==SIZE+1){
		_print();
	}
	
	int i;
	for (i=1;i<=SIZE;i++){
		if (checkCol(qRow,i) && checkDgnl(qRow,i)){
		// if no queens on the same column or diagonal	
			qCol[qRow]=i;
			dfs(qRow+1);
			qCol[qRow]=0;
		}
	}
	
	return ;
}

int main(){
	
	dfs(1);
	
	cout<<"The number of different ways of placing the queens is "<<sum<<'\n';
	return 0;
}
