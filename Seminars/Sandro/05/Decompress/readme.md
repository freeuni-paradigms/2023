---
display: false
---

# კოდირება (50 ქულა)

RNE (run-length encoding) მონაცემების კომპრესირების მექანიზმია რომელიც მიყოლებით გამეორებულ ინფორმაციას ანაცვლებს მისი სიგრძით, თუ რამდენჯერ მეორდება იგი და თვითონ გამეორებადი ინფორმაციით. მაგალითად:
\
**aabcbcbcx** კომპრესირდება როგორც **<1,2>a<2,3>bc<1,1>x**
\
**yfoofoobar** კომპრესირდება როგორც **<1,1>y<3,2>foo<3,1>bar**
\
\
ვიცით რომ გამეორებადი საბსტრინგის სიგრძე და გამეორებების რაოდენობა არ აღემატება 15-ს. ეს საშუალებას გვაძლევს ორივე მონაცემი ერთ ბაიტში ჩავწეროთ რომლის პირველი 4 ბიტიც აღნიშნავს გამეორებადი ინფორმაციის სიგრძეს ხოლო ბოლო 4 ბაიტი თუ რამდენჯერ მეორდება იგი. ანუ საბოლოოდ aabcbcbcx კოდირდება როგორც:
\
\
**00010010 | a | 00100011 | b | c | 00010001 | x**
\
\
თქვენი ამოცანაა იმპლემენტაცია გაუკეთოთ ფუნქციას რომელიც მოცემულ `\0`-ით დასრულებულ კომპრესირებული ინფორმაციას დეკომპრესირებას გაუკეთებს.
Decompress ფუნქციის გამოძახების შემდეგ გადაცემული char\*\* ცვლადი უნდა უთითებდეს დეკომპრესირებულ C-სტრინგს(char\*).

---

```c
// Decompresses given RNE compressed data.
// Takes ownership of memory block pointed by passed data pointer.
// Char array pointed by data ends with ‘\0’.
// After returning data must be pointing to a memory block which contains decompressed
// information ownership of which is passed back to the caller.
void Decompress(char** data);
```
