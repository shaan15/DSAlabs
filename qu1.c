#include <stdio.h>
#include <string.h>

int main(){

	char A[100], B[100];

	scanf("%s %s", A,B);

	int len1 = strlen(A);
	int len2 = strlen(B);

	printf("%s %d\n", A , len1 );
	printf("%s %d\n", B , len2 );

	if(len2 != len1){
		printf("NO\n");
		return 0;
	}


	int a[26] , b[26] , i;
	for (i = 0; i < 26; ++i)
	{
		a[i] = 0 ; b[i] = 0;
	}

	for( i = 0 ; i<len1 ; i++){
		a[ A[i] - 'a'  ]++ ;
		b[ B[i] - 'a'  ]++ ;
			
	}

	for( i = 0 ; i<len1 ; i++)
		if(a[i] != b[i]){
			printf("NO\n");
			return 0;
		}

	printf("YES\n");
	return 0;
}