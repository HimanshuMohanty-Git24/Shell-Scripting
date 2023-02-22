#wap in shell script to check wheter a character is a small letter,capital letter,integer or a special character using switch case
echo "Enter a character"    
read ch
case $ch in
[a-z]) echo "Small letter";;
[A-Z]) echo "Capital letter";;
[0-9]) echo "Integer";;
*) echo "Special character";;
esac