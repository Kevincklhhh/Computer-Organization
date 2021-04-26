#include <stdlib.h>
#include <stdio.h>

int array[4] = {5, 12, 3, -1};

void main (){
	int *ptr = array;

	while (*ptr != -1){
		int local = *ptr;
		int factor = 1;
		while (local != 0){
			//factor = factor * local;
			int l_local = local;
			int l_factor = factor;
			while (l_local > 1){
				factor = factor + l_factor;
				l_local--;
			}
			local--;
		}

		ptr++;
		printf("%d\n", factor);
	}
}
