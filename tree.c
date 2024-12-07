#include <stdio.h>

int main(void){
long shorty=0L;
long lofty=0L;
long feet=0L;
long inches=0L;
long shorty_to_lofty=0L;
long lofty_to_tree=0L;
long tree_height=0L;
const long inches_per_foot=12L;

printf("Enter Lofty's height to the top of his head,in whole feet:");
scanf("%ld",&feet);
printf("            ……and then inches:");
scanf("%ld",&inches);
lofty=feet*inches_per_foot+inches;

printf("Enter Shorty's height up to his eyes,in whole feet:");
scanf("%ld",&feet);
printf("            ……and then inches:");
scanf("%ld",&inches);
shorty=feet*inches_per_foot+inches;

printf("Enter the distance between Shorty and Lofty,in whole feet:");
scanf("%ld",&feet);
printf("            ……and then inches:");
scanf("%ld",&inches);
shorty_to_lofty=feet*inches_per_foot+inches;

printf("Finally enter the distance from Lofty to the tree to the nearest foot:");
scanf("%ld",&feet);
lofty_to_tree=feet*inches_per_foot;
tree_height=shorty+(shorty_to_lofty+lofty_to_tree)*(lofty-shorty)/shorty_to_lofty;
printf("The height of the tree is %ld feet and %ld inches.\n",tree_height/inches_per_foot,tree_height%inches_per_foot);
return 0;
}
