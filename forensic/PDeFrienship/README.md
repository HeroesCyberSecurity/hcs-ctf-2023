# Lend me your signature

Author: abdierryy

Category: Forensic

Flag: `HCS{PDF_IS_FRIENDS_OF_ALL}`

## Description
PDeF dan XeMaiL adalah sahabat dan teman baik, walaupun keduanya berasal dari negara yang berbeda namun mereka bisa akrab karena keduanya menggunakan bahasa yang sama pada saat berinteraksi

## Difficulty
Advance

## Solution

Pada deskripsi diberikan sebuah clue yaitu hubungan antara PDF dan XML, untuk mengetahui lebih lanjut kita dapat melakukan convert dari pdf ke xml

Selanjutnya kita akan mendapatkan file base64

![POC 1](images/POC%201.jpg)

Lalu kita coba decrypt dan lakukan render ke gambar menggunakan `Cyberchef`

![POC 2](images/POC%202.jpg)

Kita mendapatkan sebuah gambar dari sebuah link, mari kita kunjungi link tersebut

![POC 3](images/POC%203.jpg)

Terdapat sebuah base64 lagi, jadi mari kita decrypt

![POC 4](images/POC%204.jpg)

Kita mendapatkan sebuah text, namun seperti nya ada yg aneh seperti ini dimana terdapat huruf uppercase ditengah - tengah huruf lowercase

![POC 4](images/POC%205.jpg)

Karena tidak mau menghabiskan waktu untuk mencari satu - satu, kita bisa melakukan scripting seperti ini untuk menemukan teks uppercase

```
# PDF_IS_FRIENDS_OF_ALL

text = '''
in the taestry of life, a thread so true,
friendshiP's bond emerges in vibrant hue.
two souls entwined, a journey to embark,
a symphony of trust, lighting up the Dark.

through valleys low and mountains high,
Friendship's wings help us touch the sky.
a shelter In storms, a beacon in the night,
guiding us forward with itS gentle light.

like a spring's first bloom, Friendships start,
nurtured by kindness from the heart.
in laughter shared and tears that fall,
we find solace in each otheR's call.

different as rivers that wind and twist,
yet merging in harmony, never to resist.
united in purpose, hand In hand,
friendship's dancE across the land.

in the garden of life, friendship's a flower,
blooming with grace, its fragrance a shower.
watered by moments, both big aNd small,
it stands strong anD tall, never to fall.

with empathy as its rootS and joy as its leaves,
friendship's magic sOothes and relieves.
in the gallery of memories, portraits bright,
Friendship paints colors of sheer delight.

distance may stretch its threads thin,
but in the heart's canvas, it's woven in.
time may age the stories we've spun,
but friendship's melody cAn never be undone.

so Let's raise a toast to bonds that bind,
a treasure of the heart, one of a kind.
through life's ebb and flow, hand in hand,
friendship's symphony pLays, forever grand
'''

for char in text:
    if char.isupper():
        print(char)
```

Sehingga akan muncul seperti ini

`PDFISFRIENDSOFALL`

Karena sesuai format kita harus melakukan warp dengan HCS{}, lalu menambahkan uppercase di setiap penggalan kata
