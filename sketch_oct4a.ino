const int buzzerPin = 8;

// 1. 音符-频率对应表（C大调常用音符，单位：Hz）
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// 2. 《小星星》音符序列（对应上述定义的音符）
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, 
  NOTE_A4, NOTE_A4, NOTE_G4, 
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, 
  NOTE_D4, NOTE_D4, NOTE_C4
};

// 3. 每个音符的节拍（4=1拍，8=半拍，数值越大音越长）
int noteDuration[] = {
  4,4,4,4,
  4,4,8,
  4,4,4,4,
  4,4,8
};

void setup() {
  // 无需初始化引脚（tone() 自动处理）
}

void loop() {
  // 遍历音符序列，逐个播放
  for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
    // 计算音符时长：默认 1拍=500ms，节拍值越小，音越短（8=250ms，4=500ms）
    int duration = 1000 / noteDuration[i]; 
    
    tone(buzzerPin, melody[i], duration);  // 播放当前音符
    delay(duration + 50);  // 等待音符播放完成，+50ms 是音符间的间隔（避免连音）
  }
  
  noTone(buzzerPin);      // 播放完所有音符后停止
  delay(3000);            // 等待3秒后重新播放
}