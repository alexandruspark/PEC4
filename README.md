# PEC4
Car comparison
Program in C that compares two cars and indicates which one is better depending on power, fuel consumption and price.
A car will be considered better than the other if its fuel consumption per 100 km is lower. In
case of a tie, the one with the better power-to-price ratio (i.e., the higher value) will be
considered better. If there is still a tie, we will compare the model names alphabetically and
choose the first one (for example, if we compare the names “CCC” and “AAA”, we will
select “AAA”).

Example:

If the content of the files are:

Skoda_Fabia_MPI_1.0 80 7.2 21500
BMW_X1_Hri_2.4 220 7.2 42500

The program has to display the following output per screen:
INPUT
FILENAME1?
car3.txt
FILENAME2?
car2.txt
4
OUTPUT
THE BEST CAR IS BMW_X1_Hri_2.4
