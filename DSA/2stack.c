    #include <stdio.h>
    
    //Global Variable and function prototype Declaration
    int stack[100],choice,n,top,x,i;
    void push(void);
    void pop(void);
    void display(void);
    int main()
    {
        //Asking user to input stack size
        printf("\n Enter the size of the stack (upto 100) :");
        scanf("%d",&n);
        top=-1;
        
        while(choice!=4){
        
        //Displaying Menu
        printf("\n STACK OPERATIONS: ");
        printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit");
    
            printf("\n Enter the Choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                
                    push();
                    break;
                
                case 2:
                
                    pop();
                    break;
                
                case 3:
                
                    display();
                    break;
                
                case 4:
                
                    printf("\n The program is exited !! ");
                    break;
                
                default:
                
                    printf ("\n\t Invalid Option !!!");
                
                    
            }
           printf("\n");
        };    
        return 0;
    }
    // Function for push operation
    void push()
    {
        if(top>=n-1)
        {
            printf("\n \tStack Overflow !!!");
            
        }
        else
        {
            printf("\n \tEnter a value to be pushed:");
            scanf("%d",&x);
            top++;
            stack[top]=x;
        }
    }
    
    //Function for pop operation
    
    void pop()
    {
        if(top<=-1)
        {
            printf("\n \tStack Underflow!!!");
        }
        else
        {
            printf("\n \tPopped Element:  %d",stack[top]);
            top--;
        }
    }
    
    //Function for displaying the elements in stack
    void display()
    {
        if(top>=0)
        {
            printf("\n \tElements in Stack : ");
            for(i=top; i>=0; i--)
                printf("\n \t%d",stack[i]);
        }
        else
        {
            printf("\n Stack is null !!!");
        }
       
    }
