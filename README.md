Question 1:Design and Implement a Stack Using an Array
Aim:- To design and implement a stack using an array in C language without using any built-in stack library. The program performs PUSH, POP, PEEK, and DISPLAY operations and handles stack overflow and stack underflow conditions.
Theory:- A stack is a linear data structure that follows the LIFO (Last In, First Out) principle. This means that the element inserted last is removed first. For example, a stack of books: the book placed on top is removed first. Basic operations of a stack:-
.PUSH(x): Inserts an element into the stack.
.POP(): Removes the top element from the stack.
.PEEK(): Displays the top element without removing it.
.DISPLAY(): Displays all elements present in the stack.
Stack diagram Stack (LIFO)
30 — TOP 20 10 POP removes 30 first; PUSH inserts a new element at the top.
Algorithm:-
PUSH(x)
Check whether top == MAX - 1. If true, display Stack Overflow. Otherwise, increment top and insert the element. Stop.
POP()
Check whether top == -1. If true, display Stack Underflow. Otherwise, display the top element and decrement top. Stop.
PEEK()
Check whether the stack is empty. If empty, display an appropriate message. Otherwise, display stack[top].
DISPLAY() Check whether the stack is empty. If not, display all elements from top to index 0.
C program: #include <stdio.h> #define MAX 5
int stack[MAX]; int top = -1;
void PUSH(int x) { if (top == MAX - 1) { printf("Stack Overflow\n"); return; }
stack[++top] = x;
printf("%d pushed into stack\n", x);
}
void POP() { if (top == -1) { printf("Stack Underflow\n"); return; }
printf("Popped element: %d\n", stack[top--]);
}
void PEEK() { if (top == -1) { printf("Stack is empty\n"); return; }
printf("Top element: %d\n", stack[top]);
}
void DISPLAY() { int i;
if (top == -1)
{
    printf("Stack is empty\n");
    return;
}

printf("Stack elements are:\n");

for (i = top; i >= 0; i--)
{
    printf("%d\n", stack[i]);
}
}
int main() { int choice, x;
do
{
    printf("\n1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEEK\n");
    printf("4. DISPLAY\n");
    printf("5. EXIT\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            PUSH(x);
            break;
        case 2:
            POP();
            break;
        case 3:
            PEEK();
            break;
        case 4:
            DISPLAY();
            break;
        case 5:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
    }

} while (choice != 5);

return 0;
}
Output --- STACK MENU ---
PUSH
POP
PEEK
DISPLAY
EXIT
Enter your choice: 1 Enter value: 10 10 pushed onto the stack.
Enter your choice: 1 Enter value: 20 20 pushed onto the stack.
Enter your choice: 1 Enter value: 30 30 pushed onto the stack.
Enter your choice: 4 Stack elements are: 30 20 10
Enter your choice: 3 Top element: 30 Enter your choice: 2 Popped element: 30
Stack Overflow and Stack Underflow:-
Stack Overflow: It occurs when we try to insert an element into a stack that is already full. For an array of size 5, attempting to insert a sixth element causes overflow. Stack Underflow: It occurs when we try to remove an element from an empty stack or access its top element when no element exists.
What happens when the stack has a fixed size? The stack can store only a limited number of elements. If the array is full, another PUSH operation is rejected and an overflow message is displayed. The existing elements remain unchanged.
Time and Space Complexity:- Operation Time Complexity PUSH O(1)
POP O(1)
PEEK O(1)
DISPLAY O(n)
Space Complexity: O(MAX), because a fixed-size array is used to store the elements. Here, n represents the number of elements in the stack.
Result:- Thus, a stack was successfully implemented using an array in C language. The program performs PUSH, POP, PEEK, and DISPLAY operations and handles stack overflow and underflow conditions.
Question 2:-Implement a Circular Queue Using an Array Aim:- To implement a circular queue using an array in C language and perform ENQUEUE, DEQUEUE, FRONT, and DISPLAY operations while correctly handling full and empty queue conditions. Theory:-
A queue is a linear data structure that follows the FIFO (First In, First Out) principle. This means that the element inserted first is removed first. A circular queue is a queue in which the last position is connected to the first position. It allows the reuse of empty positions in the array.
Basic operations: ENQUEUE(x): Inserts an element at the rear of the queue.
DEQUEUE(): Removes an element from the front.
FRONT(): Displays the first element without removing it.
DISPLAY(): Displays all elements from front to rear.
Circular queue diagram Circular Queue
10 Index 0 20 Index 1 30 Index 2 — Index 3 — Index 4 FRONT = 0 REAR = 2 After the rear reaches the last index, it can wrap around to index 0 if that position is free.
Conditions for an Empty and Full Queue Empty queue condition:
front == -1 This indicates that the queue contains no elements.
Full queue condition: (rear + 1) % MAX == front This indicates that the next position after rear is already occupied by front.
Algorithm:- ENQUEUE(x)
Check whether the queue is full. If full, display Queue Overflow. If the queue is empty, set front = rear = 0. Otherwise, update rear = (rear + 1) % MAX. Insert the element at queue[rear].
DEQUEUE() Check whether the queue is empty. If empty, display Queue Underflow. Otherwise, remove and display the element at queue[front]. If front == rear, reset both indices to -1. Otherwise, update front = (front + 1) % MAX.
FRONT() Check whether the queue is empty. If empty, display an appropriate message. Otherwise, display queue[front].
DISPLAY() Check whether the queue is empty. Start from front. Display each element while moving circularly through the array. Stop after displaying the element at rear.
C program #include <stdio.h> #define MAX 5 int queue[MAX]; int front = -1; int rear = -1;
int isEmpty() { return front == -1; }
int isFull() { return (rear + 1) % MAX == front; }
void ENQUEUE(int x) { if (isFull()) { printf("Queue Overflow\n"); return; }
if (isEmpty())
{
    front = rear = 0;
}
else
{
    rear = (rear + 1) % MAX;
}

queue[rear] = x;
printf("%d enqueued into queue\n", x);
}
void DEQUEUE() { if (isEmpty()) { printf("Queue Underflow\n"); return; }
printf("Dequeued element: %d\n", queue[front]);

if (front == rear)
{
    front = rear = -1;
}
else
{
    front = (front + 1) % MAX;
}
} void FRONT() { if (isEmpty()) { printf("Queue is empty\n"); return; }
printf("Front element: %d\n", queue[front]);
} void DISPLAY() { int i;
if (isEmpty())
{
    printf("Queue is empty\n");
    return;
}

printf("Queue elements are: ");
i = front;
while (1) { printf("%d ", queue[i]);
    if (i == rear)
    {
        break;
    }

    i = (i + 1) % MAX;
}

printf("\n");
}
int main() { int choice, x;
do
{
    printf("\n1. ENQUEUE\n");
    printf("2. DEQUEUE\n");
    printf("3. FRONT\n");
    printf("4. DISPLAY\n");
    printf("5. EXIT\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            ENQUEUE(x);
            break;
        case 2:
            DEQUEUE();
            break;
        case 3:
            FRONT();
            break;
        case 4:
            DISPLAY();
            break;
        case 5:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
    }

} while (choice != 5);

return 0;
} Output:- --- CIRCULAR QUEUE MENU ---
ENQUEUE
DEQUEUE
FRONT
DISPLAY
EXIT
Enter your choice: 1 Enter value: 10 10 enqueued successfully.
Enter your choice: 1 Enter value: 20 20 enqueued successfully.
Enter your choice: 1 Enter value: 30 30 enqueued successfully.
Enter your choice: 4 Queue elements are: 10 20 30
Enter your choice: 3 Front element: 10
Enter your choice: 2 Dequeued element: 10
Enter your choice: 4 Queue elements are: 20 30
1-Why Does a Circular Queue Provide Better Memory Utilization? In a simple linear queue, when elements are removed from the front, the earlier array positions become empty. However, in a basic implementation without shifting, these positions cannot be reused once rear reaches the last index. This situation is called false overflow because empty positions exist, but the queue cannot use them. circular queue solves this problem by allowing rear to wrap around to the beginning of the array using the modulo operator %. Therefore, previously freed positions can be reused until the queue becomes genuinely full.
2-Time and Space Complexity:-
Operation Time Complexity ENQUEUE O(1)
DEQUEUE O(1)
FRONT O(1)
DISPLAY O(n)
3-Space Complexity: O(MAX), because a fixed-size array is used to store the queue elements. Here, n represents the number of elements currently present in the queue. Problem in Linear Queue (False Overflow)
4-What problem occurs in a linear queue when REAR reaches the last index even though unused positions exist at the beginning? When the REAR pointer reaches the last index of a linear queue, no more elements can be inserted, even if some positions at the beginning of the array are empty due to deletion operations. This problem is called False Overflow. Example: Suppose a queue has five positions: [_, _, 30, 40, 50]. The first two positions are empty, but if REAR has reached the last index, insertion is not possible in a basic linear queue implementation. Solution: A circular queue solves this problem by allowing the REAR pointer to return to the beginning of the array using the modulo (%) operator, provided a free position is available.
Result:- Thus, a circular queue was successfully implemented using an array in C language. The program performs ENQUEUE, DEQUEUE, FRONT, and DISPLAY operations and correctly handles full and empty queue conditions.
