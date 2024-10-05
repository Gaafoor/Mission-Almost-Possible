int ra1 = 1;
int ra2 = 2;
int ra3 = 3;
int rb1 = 4;
int rb2 = 5;
int rb3 = 6;
int rc1 = 7;
int rc2 = 8;
int rc3 = 9;
int ba1 = 10;
int ba2 = 11;
int ba3 = 12;
int bb1 = 13;
int bb2 = A0;
int bb3 = A1;
int bc1 = A2;
int bc2 = A3;
int bc3 = A4;
int ra1State;
int ra2State;
int ra3State;
int rb1State;
int rb2State;
int rb3State;
int rc1State;
int rc2State;
int rc3State;
int ba1State;
int ba2State;
int ba3State;
int bb1State;
int bb2State;
int bb3State;
int bc1State;
int bc2State;
int bc3State;

int playerMovesr[3]; // Array to store the last three moves for the current player
int playerMovesb[3]; // Array to store the last three moves for the current player
int moveCounterr = 0; // Counter to track the number of moves
int moveCounterb = 0; // Counter to track the number of moves

void playerMoveb(int spot) {
  // Save the player's move
  playerMovesb[moveCounterb] = spot;
  moveCounterb++;

  // If this is the third move, check for a win
  if (moveCounterb == 3) {
    if (!checkWin()) {
      // If the player didn't win, delete the first move
      deleteMove(playerMovesb[0]);
      shiftMovesb();
      moveCounterb = 2; // Reset the counter to two since the first move is deleted
    }
  }
}

void playerMover(int spot) {
  // Save the player's move
  playerMovesr[moveCounterr] = spot;
  moveCounterr++;

  // If this is the third move, check for a win
  if (moveCounterr == 3) {
    if (!checkWin()) {
      // If the player didn't win, delete the first move
      deleteMove(playerMovesr[0]);
      shiftMovesr();
      moveCounterr = 2; // Reset the counter to two since the first move is deleted
    }
  }
}

void deleteMove(int spot) {
  // Reset the spot so it can be played again
  digitalWrite(spot, LOW); // Assuming LOW indicates an empty spot
}



void shiftMovesr() {
  // Shift the remaining moves in the array to the left
  playerMovesr[0] = playerMovesr[1];
  playerMovesr[1] = playerMovesr[2];
}
void shiftMovesb() {
  // Shift the remaining moves in the array to the left
  playerMovesb[0] = playerMovesb[1];
  playerMovesb[1] = playerMovesb[2];
}
bool checkWin() {
  // Check horizontal wins for red
  if (digitalRead(ra1) == HIGH && digitalRead(ra2) == HIGH && digitalRead(ra3) == HIGH) return true; // Row 1
  if (digitalRead(rb1) == HIGH && digitalRead(rb2) == HIGH && digitalRead(rb3) == HIGH) return true; // Row 2
  if (digitalRead(rc1) == HIGH && digitalRead(rc2) == HIGH && digitalRead(rc3) == HIGH) return true; // Row 3

  // Check vertical wins for red
  if (digitalRead(ra1) == HIGH && digitalRead(rb1) == HIGH && digitalRead(rc1) == HIGH) return true; // Column 1
  if (digitalRead(ra2) == HIGH && digitalRead(rb2) == HIGH && digitalRead(rc2) == HIGH) return true; // Column 2
  if (digitalRead(ra3) == HIGH && digitalRead(rb3) == HIGH && digitalRead(rc3) == HIGH) return true; // Column 3

  // Check diagonal wins for red
  if (digitalRead(ra1) == HIGH && digitalRead(rb2) == HIGH && digitalRead(rc3) == HIGH) return true; // Diagonal \
  if (digitalRead(ra3) == HIGH && digitalRead(rb2) == HIGH && digitalRead(rc1) == HIGH) return true; // Diagonal /

  // Check horizontal wins for blue
  if (digitalRead(ba1) == HIGH && digitalRead(ba2) == HIGH && digitalRead(ba3) == HIGH) return true; // Row 1
  if (digitalRead(bb1) == HIGH && digitalRead(bb2) == HIGH && digitalRead(bb3) == HIGH) return true; // Row 2
  if (digitalRead(bc1) == HIGH && digitalRead(bc2) == HIGH && digitalRead(bc3) == HIGH) return true; // Row 3

  // Check vertical wins for blue
  if (digitalRead(ba1) == HIGH && digitalRead(bb1) == HIGH && digitalRead(bc1) == HIGH) return true; // Column 1
  if (digitalRead(ba2) == HIGH && digitalRead(bb2) == HIGH && digitalRead(bc2) == HIGH) return true; // Column 2
  if (digitalRead(ba3) == HIGH && digitalRead(bb3) == HIGH && digitalRead(bc3) == HIGH) return true; // Column 3

  // Check diagonal wins for blue
  if (digitalRead(ba1) == HIGH && digitalRead(bb2) == HIGH && digitalRead(bc3) == HIGH) return true; // Diagonal \
  if (digitalRead(ba3) == HIGH && digitalRead(bb2) == HIGH && digitalRead(bc1) == HIGH) return true; // Diagonal /

  return false; // No winner
}


void setup() {
  // put your setup code here, to run once:
 pinMode(ra1, OUTPUT);
  pinMode(ra2, OUTPUT);
  pinMode(ra3, OUTPUT);
  pinMode(rb1, OUTPUT);
  pinMode(rb2, OUTPUT);
  pinMode(rb3, OUTPUT);
  pinMode(rc1, OUTPUT);
  pinMode(rc2, OUTPUT);
  pinMode(rc3, OUTPUT);
  pinMode(ba1, OUTPUT);
  pinMode(ba2, OUTPUT);
  pinMode(ba3, OUTPUT);
  pinMode(bb1, OUTPUT);
  pinMode(bb2, OUTPUT);
  pinMode(bb3, OUTPUT);
  pinMode(bc1, OUTPUT);
  pinMode(bc2, OUTPUT);
  pinMode(bc3, OUTPUT);

  bb2State = 1;
  x();
  bb2State = 0;

  ra3State = 1;
  x();
  ra3State = 0;

  bc2State = 1;
  x();
  bc2State = 0;

  rc1State = 1;
  x();
  rc1State = 0;

  ba1State = 1;
  x();
  ba1State = 0;
  
  rc2State = 1;
  x();
  rc2State = 0;

  ba2State = 1;
  x();
  ba2State = 0;

  rb1State = 1;
  x();
  rb1State= 0;

   ba3State = 1;
  x();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void x (){
  
  
   if (digitalRead(ra1) == LOW && ba1State == 1) 
{
  digitalWrite(ba1, HIGH);
  playerMoveb(ba1);
}
else if (digitalRead(ba1) == LOW && ra1State == 1)
{
  digitalWrite(ra1, HIGH);
  playerMover(ra1);
}

else if (digitalRead(ra2) == LOW && ba2State == 1)
{
  digitalWrite(ba2, HIGH);
  playerMoveb(ba2);
}

else if (digitalRead(ba2) == LOW && ra2State == 1)
{
  digitalWrite(ra2, HIGH);
  playerMover(ra2);
}

else if (digitalRead(ra3) == LOW && ba3State == 1)
{
  digitalWrite(ba3, HIGH);
  playerMoveb(ba3);
}

else if (digitalRead(ba3) == LOW && ra3State == 1)
{
  digitalWrite(ra3, HIGH);
  playerMover(ra3);
}

else if (digitalRead(rb1) == LOW && bb1State == 1)
{
  digitalWrite(bb1, HIGH);
  playerMoveb(bb1);
}

else if (digitalRead(bb1) == LOW && rb1State == 1)
{
  digitalWrite(rb1, HIGH);
  playerMover(rb1);
}

else if (digitalRead(rb2) == LOW && bb2State == 1)
{
  digitalWrite(bb2, HIGH);
  playerMoveb(bb2);
}

else if (digitalRead(bb2) == LOW && rb2State == 1)
{
  digitalWrite(rb2, HIGH);
  playerMover(rb2);
}

else if (digitalRead(rb3) == LOW && bb3State == 1)
{
  digitalWrite(bb3, HIGH);
  playerMoveb(bb3);
}

else if (digitalRead(bb3) == LOW && rb3State == 1)
{
  digitalWrite(rb3, HIGH);
  playerMover(rb3);
}

else if (digitalRead(rc1) == LOW && bc1State == 1)
{
  digitalWrite(bc1, HIGH);
  playerMoveb(bc1);
}

else if (digitalRead(bc1) == LOW && rc1State == 1)
{
  digitalWrite(rc1, HIGH);
  playerMover(rc1);
}

else if (digitalRead(rc2) == LOW && bc2State == 1)
{
  digitalWrite(bc2, HIGH);
  playerMoveb(bc2);
}

else if (digitalRead(bc2) == LOW && rc2State == 1)
{
  digitalWrite(rc2, HIGH);
  playerMover(rc2);
}

else if (digitalRead(rc3) == LOW && bc3State == 1)
{
  digitalWrite(bc3, HIGH);
  playerMoveb(bc3);
}

else if (digitalRead(bc3) == LOW && rc3State == 1)
{
  digitalWrite(rc3, HIGH);
  playerMover(rc3);
}
delay(5000);
}
