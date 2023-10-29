დავუშვათ ამ რეპოზიტორიის მისამართი ლოკალურ დისკზე (თქვენს მანქანაზე) არის: `/Users/lekva/teach/freeuni/paradigms/2023`

## ინსტალაცია
```sh
bash asm/download_tools.sh
```

## ლოკალურად გაშვება
დავუშვათ `/tmp/foo` დირექტორიაში გაქვთ შენახული ასემბლერის ფაილი რომლის გაშვებაც გინდათ ემულატორის საშუალებით.  
ტერმინალის გამოყენებით ჯერ შედით ამ დირექტორიაში:
```sh
cd /tmp/foo
```
აქ არსებული min.s ასემბლი ფაილის გასაშვებათ ტერმინალში გაუშვით:
```sh
java -jar /Users/lekva/teach/freeuni/paradigms/2023/ams/venus.jar min.s
```

## ონლაინ სიმულატორი
იგივე დირექტორიაში გაუშვით
```sh
java -jar /Users/lekva/teach/freeuni/paradigms/2023/asm/venus.jar . -dm
```

ამ ბრძანების გაშვების შედეგად ტერმინალში უნდა დაიბეჭდოს დიდი `Javalin` ლოგო.  
თუ `port unable to be bound` შეცდომა ამოგიგდოთ, მაშინ ტერმინალში თავიდან გაუშვით (6162-ის ნაცვლად სხვა პორტის ნომერი შეგიძლიათ მიუთითოთ):
```sh
java -jar https://github.com/freeuni-paradigms/2023/tree/main/asm/venus.jar . -dm --port 6162
```

![Javalin](https://github.com/freeuni-paradigms/2023/raw/main/asm/01.png)

ამის შემდეგ ბრაუზერში გახსენით შემდეგი მისამართი [http://venus.cs61c.org/](http://venus.cs61c.org/)  
venus ის ტერმინალში გაუშვით შემდეგი ბრძანება:
```sh
mount local paradigms
```

დაბრუნდით თქვენს მანქანაზე და იქ დაბეჭდილი security კოდი დააკოპირეთ ბრაუზერში. რის შემდეგაც Files ტაბში გამოგიჩნდებათ `/tmp/foo` დირექტორია. შეგიძლიათ ბრაუზერშივე გახსნათ და დაარედაქტიროთ ფაილები.  

![files-1](https://github.com/freeuni-paradigms/2023/raw/main/asm/02.png)
![files-2](https://github.com/freeuni-paradigms/2023/raw/main/asm/03.png)
![files-3](https://github.com/freeuni-paradigms/2023/raw/main/asm/04.png)

Simulator ტაბში შეგიძლიათ გაუშვათ (Run) ან დაადებაგოთ თქვენი ასემბლი კოდი Step ღილაკის გამოყენებით.

![simulator](https://github.com/freeuni-paradigms/2023/raw/main/asm/05.png)


## Venus ემულატორის დოკუმენტაცია
[https://inst.eecs.berkeley.edu/~cs61c/sp23/resources/venus-reference/](https://inst.eecs.berkeley.edu/~cs61c/sp23/resources/venus-reference/)

## ecall ის დოკუმენტაცია
[https://github.com/ThaumicMekanism/venus/wiki/Environmental-Calls](https://github.com/ThaumicMekanism/venus/wiki/Environmental-Calls)
