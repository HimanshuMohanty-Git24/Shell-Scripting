#!/bin/sh

FRUIT="kiwi"

case "$FRUIT" in
   "apple") echo "Apple pie is quite tasty." 
   ;;
   "banana") echo "I like banana nut bread." 
   ;;
   "kiwi") echo "New Zealand is famous for kiwi." 
   ;;
esac
Name ="Ram"
case "$Name" in
   "Ram") echo "Hello Ram"
   ;;
   "Shyam") echo "Hello Shyam"
   ;;
   "Hari") echo "Hello Hari"
   ;;
   *) echo "Hello Guest"
   ;;
esac