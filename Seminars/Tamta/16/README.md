---
nav_order: 2
title: Bits - rugby
parent: შუალედური გამოცდის საკითხების მაგალითები
grand_parent: სავარჯიშოები
---

# Bits - rugby

რაგბის თამაშების შედეგები გვაქვს მოცემული როგორც ბაიტების მიმდევრობა. თითოეული თამაშის შედეგი წარმოდგენილია როგორც:

`<გუნდის სახელი><სფეისი><ერთ ბაიტიანი ქულა პირველი გუნდის><ერთ ბაიტიანი ქულა მეორე გუნდის><სფეისი><მეორე გუნდის სახელი>`

გუნდის სახელები შედგება დიდი და პატარა ლათინური ასოებისგან. თამაშის შედეგები გამოყოფილია წერტილ-მძიმეებით. ბოლოს თამაშის შედეგი წერტილ მძიმის ნაცვლად მთავრდება ‘\0’ სიბოლოთი. მაგალითად:

```
ascii: “a 02 b;b 10 c”
hex: 61 20 30 20 32 20 62 3b 62 20 31 20 30 20 63 00
```

თქვენი ამოცანაა იმპლემენტაცია გაუკეთოთ შემდეგ სამ ფუნქციას:

```c

// Returns total number of games played by team with given name.
int TotalGamesPlayed(void* results, char* team_name);

// Returns total points scored across all games by team with given name.
int TotalPointsScored(void* results, char* team_name);

// Returns number of games won by team with given name.
int NumWins(void* results, char* team_name);
```
