typedef struct node
{
	element e;
	struct node *next;
} nodeD;

typedef struct queueD
{
	nodeD *head;
	nodeD *tail;
} QueueD;

void createQD(QueueD *Q)
{
	Q->tail = Q->head = NULL;
}

int isEmptyQD(QueueD)
{
	if(Qhead == NULL)
		return true;
	else 
		return false;
}

void enqueueQD(QueueD *Q, element ele)
{
	nodeD *n;
	n = (nodeD*)malloc(sizeof(NodeD));
	n->e = ele;
}