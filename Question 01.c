#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define Max_Size 100


// Function to calculate the minimum number of operations required
int minimum_operation(char *S, int K)
{
	int char_count[Max_Size] = {0};
	int minimum_operation=0, front=0, rear=0;
	int queue[Max_Size];
	
	for (int i = 0; i < strlen(S); i++)
	{
		char c = S[i];
		queue[rear++] = c - 'a';
        char_count[c - 'a']++;
        
        // Check if the queue size is equal to K
        if (rear - front == K) 
		{
            // Check for duplicates and perform the operation
            for (int j = 0; j < Max_Size; j++) 
			{
                if (char_count[j] > 1) 
				{
                    minimum_operation += char_count[j] - 1;
                }
                
            }

            // Reset the count and remove the first character from the queue
            char_count[queue[front++]]--;
            
        }
	}
	return minimum_operation;
}


// Function to check if the string contains only lowercase letters
bool is_lower_case(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!islower(string[i])) {
            return false;
        }
    }
    return true;
}


int main()
{
	char S[Max_Size];
	int K;
	
	while (true)
	{
		printf("Insert the string: ");
		scanf("%s", S);
		
		if(is_lower_case(S))
		{
			break;
		} 
		else
		{
			printf("\nError:: Only lowercase letters are allowed in the input.\n\n");	
		}
	}
	
	 while (true)
	{
		printf("Insert the value of K: ");
		scanf("%d", &K);
		
		if (K < 2) 
		{
            printf("\nError:: K should be >= 2 & <= length of the string. The length of the string is %zu.\n\n", strlen(S));
        } else if (K > strlen(S)) 
		{
            printf("\nError:: K should be >= 2 & <= length of the string. The length of the string is %zu.\n\n", strlen(S));
        } else 
		{
            break;
        }
		
	}
	
	printf("Minimum number of operations required: %d\n", minimum_operation(S, K));
	
	return 0;
}
 
