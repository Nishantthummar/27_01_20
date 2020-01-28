rm funlist.a
rm funlist.o
rm myapp						
gcc -c funlist.c
ar -cvq funlist.a funlist.o
gcc manu.c -o myapp funlist.a

