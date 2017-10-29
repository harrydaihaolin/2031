#include "6-2.h"

main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}


/*addtree: add a node with w, at or below p*/
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL) /*a new word has arrived*/
	{
		p = talloc(); /*make a new node*/
		p->word = strdup(w); /*dump the string*/
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if(cond < 0)
		p->left = addtree(p->left, w);
	else 
		p->right = addtree(p->right, w);
	return p;
};

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
};

struct treeprint(struct tnode *p)
{
	if(p != NULL) /*preorder traversal*/
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
};

char *strdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}
