//Advent of code day one
// lock picking, check for land on zero

string fileLine;

ifstream MyReadFile("dayOne.txt");

while (getline (MyReadFile, fileLine)) {
  char direction = fileLine[0];
  try:
    int clicks = (int) fileLine[1,fileLine.length()];
  catch:
    cout << "Impropper input formatting";
}
