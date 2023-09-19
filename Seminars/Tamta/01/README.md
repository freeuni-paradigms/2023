## OS

შემდეგი სემინარისთვის საჭიროა დაყენებული გქონდეთ თქვენს მანქანაზე ლინუქსი (დუალ ბუტი შეგიძლიათ ან მხოლოდ ლინუქსი) ან ვირტუალური მანქანით იმუშაოთ მასზე (wsl2). მაკის მფლობელებს ჯერჯერობით შეგიძლიათ gcc პირდაპირ მაკზე დააყენოთ brew-ს გამოყენებით: brew install gcc. ასე დაწეროთ და გაუშვათ C-ის კოდები.

## Terminal

შეგიძლიათ წაიკითხოთ ინფორმაცია ტერმინალის შესახებ და ისწავლოთ მნიშვნელოვანი ბრძანებები: ls, cd, pwd, mkdir, touch, cp, mv, rm, rmdir, gcc, git, code... 

იმისთვის რომ მიეჩვიოთ, ფაილ მენეჯერის გახსნის ნაცვლად გამოიყენეთ მხოლოდ ტერმინალი.

## gcc

კოდის დასაკომპილირებლად გამოიყენეთ ბრძანება

```sh
gcc <ფაილის სახელი>
./a.out
```

მაგალითად:

```sh
gcc strings.c
./a.out
```

თუ გინდათ რომ გამშვებ ფაილს 'a.out' არ ერქვას გამოიყენეთ -o ფლეგი კომპილაციისას მაგალითად:

```sh
gcc strings.c -o strings
./strings
```

## git

საჭირო ბრძანებები:
* git clone გითჰაბის_რეპოს_ლინკი
* git init
* git add ფაილის_სახელი1 ფაილის_სახელი2 
* git commit -m "კომიტ მესიჯი"
* git push
* git status
* git log

github tutorial:
https://docs.google.com/document/d/1cpRxmGSkNf-7ynzIr1Bl-NAxfACJH5YjsLbVA4CzSCY/edit#heading=h.21n8c8zhcrj5

github-ზე დავალების ასატვირთი ტუტორიალი:
https://docs.google.com/document/d/1bQOfcLp23o-F3GR5l-ccrXNwJRv7JXRLBGIMcEh0t94/edit


