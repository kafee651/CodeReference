#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TNIL.h"



Treeptr rb_inorder_traverser(Treeptr root, Treeptr z){
	
	if(z == Tnil)
		return(root);
	root = br_inorder_traverser(root, z -> left);
	printf("%ld\t", z -> key);
	root = br_inorder_traverser(root, z -> right);
	
	return(root);
}
