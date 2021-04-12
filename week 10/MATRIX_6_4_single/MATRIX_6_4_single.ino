/*
 square of eeonyx fabric with 6 conductive rows and 6 conductive columns
 parsing through this grid by switching individual rows/columns to be 
 HIGH, LOW or INPUT (high impedance) to detect location and pressure
 >> http://howtogetwhatyouwant.at/
 */

#define numRows 6
#define numCols 4

const int lengthArray= numRows*numCols;
int rows[] = { A0, A1, A2, A3, A4, A5 };
int cols[] = { 12, 10, 9, 8};
int incomingValues[lengthArray] = {};   

void setup() {
  // set all rows and columns to INPUT (high impedance):
  for(int i=0; i<numRows; i++){
    pinMode(rows[i], INPUT)
    ;
  }
    for(int i=0; i<numCols; i++){
    pinMode(cols[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int colCount=0; colCount<numCols; colCount++){
    pinMode(cols[colCount], OUTPUT);  // set as OUTPUT
    digitalWrite(cols[colCount], LOW);  // set LOW

    for(int rowCount=0; rowCount<numRows; rowCount++){
      pinMode(rows[rowCount], INPUT_PULLUP);  // set as INPUT with PULLUP RESISTOR
      delay(1);
      incomingValues[ ( (colCount)*numRows) + (rowCount)] = analogRead(rows[rowCount]);  // read INPUT
      
      // set pin back to INPUT
      pinMode(rows[rowCount], INPUT);

    }// end rowCount

    pinMode(cols[colCount], INPUT);  // set back to INPUT!

  }// end colCount

 /*/ // Print the incoming values of the grid:
  for(int i=0; i<4; i++){
    Serial.print(incomingValues[i]);
    if(i<3) Serial.print(",");
  }
  Serial.println();
  */
  for(int i=0; i<lengthArray; i++){

    //Serial.print(incomingValues[i]);
    if(incomingValues[i]<100){
      Serial.print(i+1);
       Serial.println(",");

    }
  }

}
int largest(int flat[], int n) 
{ 
    int i; 
     
    // Initialize maximum element 
    int max = flat[0]; 
  
    // Traverse array elements from second and 
    // compare every element with current max   
    for (i = 1; i < n; i++) 
        if (flat[i] > max) 
            max = flat[i]; 
  
    return max; 
} 
