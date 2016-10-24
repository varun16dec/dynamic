#include<bits/stdc++.h>

using namespace std;

int main(){
    int noOfItems,maxWeight;
    printf("Enter no of items ,maxweight : ");
    scanf("%d%d",&noOfItems,&maxWeight);
    printf("Enter value followed by respective weight of each item : ");
    int i;
    vector<int>value(noOfItems+1,0);
    vector<int>weight(noOfItems+1,0);
    for(i=1;i<=noOfItems;i++){
        printf("\nItem no %d value , weight : " , i);
        scanf("%d%d",&value[i],&weight[i]);
    }

    for(i=0;i<=noOfItems;i++)
        printf("\nValue : %d , weight : %d",value[i],weight[i]);
    vector< vector<int> > a(noOfItems+1,vector<int>(maxWeight+1));

    int x;
    for(i=0,x=0;x<=maxWeight;x++)
        a[i][x]=0;



    for(i=1;i<=noOfItems;i++)
        for(x=0;x<=maxWeight;x++){

                if(x-weight[i]<0){
                    a[i][x]=0;
                    continue;
                }

            int p=a[i-1][x];
            int q=a[i-1][x-weight[i]]+value[i];

            if(p>q)   //case 1 : leaving ith element
                a[i][x]=p;

            else if(q>=p) //case 2: taking i th element
                a[i][x]=q;

        }

    printf("\nMatrix : \n");
    for(i=0;i<=noOfItems;i++){
        for(x=0;x<=maxWeight;x++)
            printf("%d ",a[i][x]);

        cout<<"\n";
    }

    printf("Optimal solution : %d \n",a[noOfItems][maxWeight]);

    printf("Items no included : ");
    for(i=noOfItems,x=maxWeight;i>0 && x>0;i--){
        if(x-weight[i]<=0)
            break;
        int p=a[i-1][x];

        int q=a[i-1][x-weight[i]]+value[i];
        if(q>p){
            printf("i = %d p= %d  q=%d\n",i,p,q);
            x=x-weight[i];

        }

    }
}
