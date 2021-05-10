set -e 
set -o xtrace
clang -c shell.c 
clang -c commands/compare.c
clang -c commands/create.c
clang -c commands/setup.c
clang -c commands/submit.c
clang -c commands/switch.c
clang -c commands/test.c -I. # include directory is current directory
clang -c commands/update.c
clang -c commands/use.c
clang -c directoryfunc/copyDir.c
clang -c directoryfunc/createDir.c
clang -c directoryfunc/printDir.c
clang -c io/output.c
clang -o exe.out \
  compare.o \
  copyDir.o \
  createDir.o \
  create.o \
  output.o \
  printDir.o \
  setup.o \
  shell.o \
  submit.o \
  switch.o \
  update.o \
  test.o \
  use.o 
