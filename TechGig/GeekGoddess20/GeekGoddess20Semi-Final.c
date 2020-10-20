/*
TechGig GeekGoddess2020 Open Semi-Final Test

Coding Belt (100 Marks)
A state is divided into R*C cities.The government has launched an initiative to find the cities which are dominated by coders. Each city may or may not have coders residing in it. If the city is dominated by coders, it is marked with 1 else it is marked with 0. Two cities are termed as connected cities if they both are dominated by coders and can be reached by moving vertically, horizontally, or diagonally.


Example:

The given is the state with 3*3 cities and their dominance representation.





City[1, 1] is directly connected to City[1, 2].

City[1, 2] is directly connected to City[1, 1], City[1, 3] and City[2, 3].

City[1, 3] is directly connected to City[1, 2] and City[2, 3].

City[2, 3] is directly connected to City[1, 2] and City[1, 3].

City[3, 1] is not connected to any of the other coder dominant cities.


One or more coder dominant connected cities form the Coding belt. In a belt, there may be coder dominant cities which are not directly connected but can be reached by moving through other dominant cities. It is possible that there are multiple coding belts in the state. 


Example:

The given is the state with 3*3 cities and their dominance representation.





For the given example, there are two coding belts. C1 represents Coding Belt 1 and C2 represents Coding Belt 2.

 




The government wants to find the number of coder dominant cities in the largest coding belt.

The government will give you the credits in the initiative. Can you help the government?


Note: For the given example, there are 4 coder dominant cities in the largest coding belt.

Input Format
The first line of input consists of two space-separated integers, number of rows, R, and number of columns, C.

Next R lines each consist of C space-separated integers.



Constraints
1<= R, C <=10

Output Format
Print the number of coder dominant cities in the largest Coding belt.

Sample TestCase 1
Input
5 5
1 1 1 0 0
0 1 1 0 0
0 0 0 0 1
1 0 0 1 1
1 1 0 0 1
Output
5
Explanation

There are three belts in the given 5*5 cities.





Coding Belt 1 (C1): Number of Coder Dominant Cities = 5

Coding Belt 2 (C2): Number of Coder Dominant Cities = 4

Coding Belt 3 (C3): Number of Coder Dominant Cities = 3

*/

#include<stdio.h>
int main(int argc, char *a[])
{	int r,c,n[10][10],ans=0;
	scanf("%d%d",&r,&c);
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
			scanf("%d",&n[i][j]);

    int clusterno=2;int noMoreOnes=0;

    while(noMoreOnes==0){

        //find first 1
        int x,y;int flag=0;
        for(x=0;x<r;x++){
            for(y=0;y<c;y++){
                if (n[x][y]==1){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }

        //if noMoreOnes, there is no more clusters
        if(x==r && y==c){
            noMoreOnes=1;
            break;
        }

        int qi[100],qj[100];
        qi[0]=x;
        qj[0]=y;
        int i=qi[0];
        int j=qj[0];
        int ql=1;
        int qindex=0;
        n[i][j]=clusterno;

        while(qindex<ql){
            i=qi[qindex];
            j=qj[qindex];

            if(i-1>=0 && j-1>=0){
                if(n[i-1][j-1]==1) {
                    n[i-1][j-1]=clusterno;
                    qi[ql]=i-1;
                    qj[ql]=j-1;
                    ql++;
                }
            }
            if(i-1>=0){
                if(n[i-1][j]==1) {
                    n[i-1][j]=clusterno;
                    qi[ql]=i-1;
                    qj[ql]=j;
                    ql++;
                }
            }
            if(i-1>=0 && j+1<c){
                if(n[i-1][j+1]==1) {
                    n[i-1][j+1]=clusterno;
                    qi[ql]=i-1;
                    qj[ql]=j+1;
                    ql++;
                }
            }
            if(j-1>=0){
                if(n[i][j-1]==1) {
                    n[i][j-1]=clusterno;
                    qi[ql]=i;
                    qj[ql]=j-1;
                    ql++;
                }
            }
            if(j+1<c){
                if(n[i][j+1]==1) {
                    n[i][j+1]=clusterno;
                    qi[ql]=i;
                    qj[ql]=j+1;
                    ql++;
                }
            }
            if(i+1<r && j-1>=0){
                if(n[i+1][j-1]==1) {
                    n[i+1][j-1]=clusterno;
                    qi[ql]=i+1;
                    qj[ql]=j-1;
                    ql++;
                }
            }
            if(i+1<r){
                if(n[i+1][j]==1) {
                    n[i+1][j]=clusterno;
                    qi[ql]=i+1;
                    qj[ql]=j;
                    ql++;
                }
            }
            if(i+1<r && j+1<c){
                if(n[i+1][j+1]==1) {
                    n[i+1][j+1]=clusterno;
                    qi[ql]=i+1;
                    qj[ql]=j+1;
                    ql++;
                }
            }
            qindex++;
        }

        //count the current clusterno
        int currlen=0;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(n[x][y]==clusterno)
                    currlen++;
            }
        }
        //printf("%d\n",currlen);
        if(currlen>ans)
            ans=currlen;
        clusterno++;
    }

    /*printf("\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",n[i][j]);
        }
        printf("\n");
    }*/

	printf("%d",ans);
}