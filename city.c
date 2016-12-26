#include <stdio.h>
#include <stdlib.h>
struct edge
{
	int weight;
	int src;
	int dest;
};
typedef struct edge edges;

struct node 
{
	int data;
	int weight;
	struct node *next;
};
struct vertices
{	
	int key;
	struct node *next;

};
typedef struct node node;
typedef struct vertices vertices;
vertices *arr[10004];
void insert(int root,node *temp)
{
	temp->next=arr[root]->next;
	arr[root]->next=temp;

}
void create_edge(int a,int b,int w)
{	//printf("edge");
	node *temp=(node *)malloc(sizeof(node));
	temp->data=b;
	temp->weight=w;
	insert(a,temp);

}
void graph(int x,int y,int w)
{	//printf("graph");
	create_edge(x,y,w);
}
void merge(edges a[],int n,int m,int r)
{

	// printf("%d",m);
// 	printf("%d",n);
	int n1=m-n+1;
	int n2=r-m;	
	edges L[n1];
	edges R[n2];
	int j,i,k;
	// printf("%d",n1); 
	// printf("%d",n2); 
	for (i=0;i<n1;i++)
	{
		L[i]=a[n+i];
		// L[i].dest=a[n+i].dest;
		// L[i].weight=a[n+i].weight;
		
	}
	// printf("first array\n");
	// for(i=1;i<=n1;i++)
	// {
	// 	printf("%d %d %d\n",L[i].src,L[i].dest,L[i].weight);
	// }
	for (j=0;j<n2;j++)
	{
		R[j]=a[m+j+1];
		

		
	}
	// printf("2nd array\n");
	// for(i=1;i<=n2;i++)
	// {
	// 	printf("%d %d %d\n",R[i].src,R[i].dest,R[i].weight);
	// }
		i=0;j=0;
		k=n;
		while(i<n1 && j<n2)
		{
			if(L[i].weight<R[j].weight)
			{	a[k]=L[i];
				// a[k].dest=L[i].dest;
				// a[k].weight=L[i].weight;
				i++;
			}
			else if(L[i].weight>=R[j].weight)
				{	a[k]=R[j];
					// a[k].dest=R[j].dest;
					// a[k].weight=R[j].weight;
					j++;
				}	
		k++;
		}
		while(i<n1)
		{	a[k++]=L[i++];
			// a[k].dest=L[i].dest;
			// a[k++].weight=L[i++].weight;
		}
		while(j<n2)
		{	a[k++]=R[j++];
			// a[k].dest=R[j].dest;
			// a[k++].weight=R[j++].weight;
		}
	
}


void mergesort1(edges x[],int p,int q)
{	int mid;
	
	// printf("q %d",q);
	if(p<q)
	{
		mid=(p+(q-1))/2;
		// printf("mid %d\n",mid);
		mergesort1(x,p,mid);
		mergesort1(x,mid+1,q);
		merge(x,p,mid,q);
	}
	
	
}
void display_graph(int n,int *count)
{	int i;
	for(i=1;i<=n;i++)
	{
		// printf("%d  ",i);
		node *temp;
		temp=arr[i]->next;
		while(temp!=NULL)
		{	//printf("loop");
			// printf("%d ",temp->data);
			// printf("%d",temp->weight);
			(*count)+=temp->weight;
			temp=temp->next;
			
		}
		// printf("\n");
	}
 // printf("%d\n",*count);	
}

void makeset(int a[],int n)
{	int i;
	for(i=1;i<=n;i++)
		a[i]=i;
}
int findset(int a[],int i)
{	while(a[i]!=i)
		i=a[i];
	return a[i];
}
void unionset(int y[],int a,int b,int n)
{
int z;
int temp;
temp=y[b];
y[b]=y[a];
for(z=1;z<=n;z++)
	if(y[z]==temp)
		y[z]=y[a];
}
void kruskal(edges x[],int n,int p,int m,int a[],int *count)
{int i;
	int j,k;
	for(j=0; j<=n; j++){
			arr[j] = (vertices *)malloc(sizeof(vertices));
			// arr[j]->color = 0;
			arr[j]->key = -1;
			// arr[j]->p = -1;
			// arr[j]->final = -1;
			arr[j]->next = NULL;
		}
	makeset(a,n);
	// for(i=0;i<=n;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");
	mergesort1(x,p,m);
	// for(i=0;i<n;i++)
	// 	printf("%d %d %d\n",x[i].src,x[i].dest,x[i].weight);
	for(i=1;i<=m;i++)
		if(findset(a,x[i].src)!=findset(a,x[i].dest))
			{	graph(x[i].src,x[i].dest,x[i].weight);
				unionset(a,x[i].src,x[i].dest,n);
				// for(k=0;k<=n;k++)
				// 	printf("%d",a[k]);
				// printf("\n");
			}
	display_graph(n,count);			
	// for(i=0;i<=n;i++)
	// 	printf("%d ",a[i]);	

}
int main()
{	int i,l,t,c,j,k;
	int n;
	int m,o;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&o);
	edges a[m+o+2];
	edges b[m+1];
	for(i=0;i<=m;i++)
	{
		a[i].src=0;
		a[i].dest=0;
		a[i].weight=0;

	}
	for(i=0;i<=m+o;i++)
	{
		b[i].src=0;
		b[i].dest=0;
		b[i].weight=0;

	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&l);
		scanf("%d",&t);
		scanf("%d",&c);
		a[i].src=l;
		a[i].dest=t;
		a[i].weight=c;
	}
	// for(k=0;k<m;k++)
	// {
	// 	printf("%d %d %d\n",a[k].src,a[k].dest,a[k].weight);
	// }
	// printf("%d\n",i);
	for(j=0;j<o;j++,i++)
	{

		// printf("%d\n",i);
		scanf("%d",&l);
		scanf("%d",&t);
		scanf("%d",&c);
		// i++;
		a[i].src=l;
		a[i].dest=t;
		a[i].weight=c;
		b[j].src=l;
		b[j].dest=t;
		b[j].weight=c;
		
		// printf("array");
	// 	for(k=0;k<i+1;k++)
	// {
	// 	printf("%d %d %d\n",a[k].src,a[k].dest,a[k].weight);
	// }
	}
	// printf("1 st array");
	// for(k=0;k<m+o;k++)
	// {
	// 	printf("%d %d %d\n",a[k].src,a[k].dest,a[k].weight);
	// }
	// printf("2nd array");
	// for(i=0;i<o;i++)
	// {
	// 	printf("%d %d %d\n",b[i].src,b[i].dest,b[i].weight);
	// }
	int array[n+1];
	for(i=0;i<=n;i++)
		array[i]=0;
	int count=0;
	kruskal(a,n,0,m+o,array,&count);
	printf("%d ",count);
	count=0;
	kruskal(b,n,0,o,array,&count);
		printf("%d\n",count);
	return 0;
}