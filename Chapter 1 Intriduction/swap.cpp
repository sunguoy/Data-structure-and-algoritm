#include<stdio.h>

void swap_val(int a, int b){ //传值调用
    printf("In Swap_val:  Address of a=%d, Address of b=%d \n", &a, &b);
	int temp = a;
	a = b;
	b = temp;
}


void swap_ref(int &a, int &b){ //引用调用
    printf("In Swap_ref:  Address of a=%d, Address of b=%d \n", &a, &b);
	int temp = a;
	a = b;
	b = temp;
}

void swap_pointer(int *a, int *b){ //引用调用
    printf("In Swap_pointer:  Address of a=%d, Address of b=%d \n", &a, &b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
    int x=666, y=777;
    printf("Before swap:  x=%d, y=%d \n", x, y);
    printf("Before swap:  Address of x=%d, Address of y=%d \n \n", &x, &y);


    swap_val(x,y);
    printf("After Swap_val:     x=%d, y=%d \n", x, y);
    printf("After Swap_val:  Address of x=%d, Address of y=%d \n \n", &x, &y);


    swap_ref(x,y);
    printf("After Swap_ref:     x=%d, y=%d \n", x, y);
    printf("After Swap_ref:  Address of x=%d, Address of y=%d \n \n", &x, &y);


    swap_pointer(&x,&y);
    printf("After Swap_pointer: x=%d, y=%d \n", x, y);
    printf("After Swap_pointer:  Address of x=%d, Address of y=%d \n \n", &x, &y);


    return 0;
}
