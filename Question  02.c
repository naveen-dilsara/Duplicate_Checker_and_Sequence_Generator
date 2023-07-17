#include <stdio.h>
#include <stdlib.h>

long answer = 0;

void solution(int *x, int x_size, int diff, int n) // x is size of the distinct elements array, diff is  common difference,  n is sequence length
{
    int count = 1;
    for (int i = 1; i < x_size; i++) 
	{
        if (x[i] - x[i - 1] == diff) 
		{
            ++count;
        } 
		else 
		{
            answer += (count - n + 1 > 0) ? (count - n + 1) * 2 : 0;
            count = 1;
        }
    }
    answer += (count - n + 1 > 0) ? (count - n + 1) * 2 : 0;
}


// Function to check if the sequence is in a decreasing sequence
int is_decreasing(int* arr, int size) 
{
    for (int i = 1; i < size; i++) 
	{
        if (arr[i] >= arr[i - 1]) 
		{
            return 0;  // Not a decreasing sequence
        }
    }
    return 1;  // Sequence is in a decreasing sequence
}

int main() 
{
	int s1, s2 ;

	printf("Insert the size of array A  : ");
	scanf("%d",&s1);
	int arrA[s1];

	printf("Insert the size of array B  : ");
	scanf("%d",&s2);
	int arrB[s2];

	printf("\n");
	

    int arr[s1 + s2];
    
    printf("Enter the elements of Sequence A: ");
    for (int i = 0; i < s1; i++) 
	{
        scanf("%d", &arrA[i]);
    }
    
    while (is_decreasing(arrA, s1)) 
	{
        printf("Error: Sequence A is in a decreasing sequence. Please re-enter the elements.\n");
        printf("Enter the elements of Sequence A: ");
        for (int i = 0; i < s1; i++) 
		{
            scanf("%d", &arrA[i]);
        }
        printf("\n");
    }
    
    printf("Enter the elements of Sequence B: ");
    for (int i = 0; i < s2; i++) 
	{
        scanf("%d", &arrB[i]);
    }
     // Check if array A is in a decreasing sequence
    while (is_decreasing(arrB, s2)) 
	{
        printf("Error: Sequence B is in a decreasing sequence. Please re-enter the elements.\n");
        printf("\nEnter the elements of Sequence B: ");
        for (int i = 0; i < s2; i++) 
		{
            scanf("%d", &arrB[i]);
        }
        printf("\n");
    }

    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2) 
	{
        if (arrA[i] <= arrB[j]) 
		{
            arr[k++] = arrA[i++];
        } 
		else 
		{
            arr[k++] = arrB[j++];
        }
    }
    while (i < s1) 
	{
        arr[k++] = arrA[i++];
    }
    while (j < s2) 
	{
        arr[k++] = arrB[j++];
    }

    int count = 1;
    int x[s1 + s2], x_size = 0;
    x[0] = arr[0];
    
    for (i = 1; i < s1 + s2; i++) 
	{
        if (arr[i] == arr[i - 1]) 
		{
            ++count;
        } 
		else 
		{
            if (count >= s1) 
			{
                ++answer;
            }
            x[++x_size] = arr[i];
            count = 1;
        }
    }
    if (count >= s1) 
	{
        ++answer;
    }
    ++x_size;

    if (x_size < s1) 
	{
        printf("The number of distinct arithmetic sequences: %ld\n", answer);
        return 0;
    }

    for (i = x_size - 1; i >= 0; i--) 
	{
        x[i] = x[i] - x[0];
    }

    int d = 2 * s1 / (s1 - 1);

    if (x[x_size - 1] - x[0] >= s1 - 1) 
	{
        solution(x, x_size, 1, s1);
    }

    for (i = 2; i <= d; i++) 
	{
        if (x[x_size - 1] - x[0] >= 1L * i * (s1 - 1)) 
		{
            int p[d][s2];
            int p_size[d];
            
            for (int p_index = 0; p_index < d; p_index++) 
			{
                p_size[p_index] = 0;
            }
            for (j = 0; j < x_size; j++) 
			{
                int mod = x[j] % i;
                p[mod][p_size[mod]++] = x[j];
			}
			
			for (j = 0; j < i; j++) 
			{
				if (p_size[j] >= s1) 
				{
					solution(p[j], p_size[j], i, s1);
				}
			}			
		}
	}
	
	printf("The number of distinct arithmetic sequences: %ld\n", answer);
	
	return 0;
}
