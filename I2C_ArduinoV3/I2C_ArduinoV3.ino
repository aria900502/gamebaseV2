#include <Wire.h>
#include <SCoop.h>
/*
'''
value ->0 =>請求order     
        1 =>請求Frist 裝置 
        2 =>請求Secend裝置
        3 =>伺服馬達指令

        65-90 =>大寫英文  
        97-112=>小寫英文 -97  0-26 =>a-z  30-33 =>指令
        ord('a') => 97 
        char(97) => a
        i2c 位元 ->0-255
'''
*/
int SLAVE_ADDRESS = 1;  // 設定Arduino開發板I2C的位址
int number = 255;
char firstWord = 255;
char secWord = 255;
class Msg{
  public:
    void setFirstWord(char);//1XX
    void setSecWord(char);//2XX
    char getFirstWord(void);//+97
    char getSecWord(void);//+97
    void sendFirstWord(void);
    void sendSeWord(void);
    
  private:
    char FirstWord;
    char SecWord;  
    
    
  };

  
class DeviceMsg{
  public:
    void setOrder(int);
    int getOrder(void);
  private:
    int order;
};


void Msg::setFirstWord(char FirstWord){
  this->FirstWord = FirstWord;
}
void Msg::setSecWord(char SecWord){
  this->SecWord = SecWord;
}
char Msg::getFirstWord(){
  return this -> FirstWord;
}
char Msg::getSecWord(){
  return this -> SecWord;
}
void Msg::sendFirstWord(){
  Wire.write(this -> getFirstWord());
}
void Msg::sendSeWord(){
  Wire.write(this -> getSecWord());
}

void DeviceMsg::getOrder(){
  return this ->order;
  }
void DeviceMsg::setOrder(int order){
  
  }











Msg msg;

DeviceMsg DM;

int waitSend = 255;
void receiveData(int byteCount){
while(Wire.available()) {
  number = Wire.read();   //指定nubmer 等於讀取的訊息
  if(number == 0){
    waitSend = DM.getOrder()
  Serial.print("num: ");
  Serial.println(number);
  Serial.print("waitSend: ");
  Serial.println(waitSend);
  }
}
void sendData(){
    number = Wire.read();
    
    if(number == 1){
      msg.sendFirstWord();
      }else if(number == 2){
        msg.sendSecWord();
        }
    Wire.write(SLAVE_ADDRESS);
    Wire.begin(SLAVE_ADDRESS); 
}  



void setup() {
  mySCoop.start(); 
}

void loop() {
  yield();
}

defineTask(I2c); 
  void I2c::setup() {
    Serial.begin(9600);   // Serial通訊埠通訊設為9600速率
    Wire.begin(SLAVE_ADDRESS);  // 初始化Arduino的I2C位址
    
    Wire.onReceive(receiveData); //I2C訊號接收時，啟用函式
    
    Wire.onRequest(sendData);  //主機要求讀取時，啟用函式
    } 
  void I2c::loop() {
    
    } 

defineTask(servusControl); 
  void servusControl::setup() {
  }
  void servusControl::loop() {
  } 