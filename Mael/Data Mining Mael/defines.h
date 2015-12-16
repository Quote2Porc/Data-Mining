#ifndef DEFINES
#define DEFINES

#define NULL 0

#define LIST 0
#define TREE 1
#define DATA_STREAM_SUMMARY 2



typedef struct link{
struct link* previous;
struct link* next;
char item;
int counter;
}  Link;

typedef Link* List;

#endif
