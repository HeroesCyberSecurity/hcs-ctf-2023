def main():
    questions = [
        {
            "question": "Sebutkan nama dan versi server yang digunakan oleh perusahaan yang sedang dianalisis?",
            "format": "Apache/99.99"
        },
        { 
            "question": "Disaat penyerang mencoba memasukkan beberapa credential pada website, sebutkan username dan hash dimana penyerang pertama kali berhasil login ke dalam website",
            "format": "budi:abcdefghjijklmnop12345678abcdefghjijklmnop12345678"
        },
        { 
            "question": "Sebutkan IP beserta port yang digunakan penyerang untuk masuk ke dalam server?",
            "format": "11.22.333.44:1234"
        },
        { 
            "question": "Sebutkan nama file (beserta full pathnya) yang ditaruh peretas didalam server?",
            "format": "/home/contoh/test.evil"
        },
    ]

    answers = [
        "mailtrail/0.53",
        "admin:56dd090935480e98650bc29cd0734ca2505f4106a315b223d9e6e2d9bc3edd73",
        "159.223.33.240:9999",
        "/tmp/.hmm.sh"
    ]

    print("Halo Budi. Silahkan jawab pertanyaan-pertanyaan yang telah disediakan:")

    correct_answers = 0

    for index, q in enumerate(questions, start=1):
        print(f"\nNo {index}:")
        print("Pertanyaan: " + q["question"])
        print("Format: " + q["format"])
        user_answer = input("Jawaban: ")

        if user_answer.strip().lower() == answers[index - 1].lower():
            correct_answers += 1
            print("Correct")
        else:
            print("Incorrect")
            return
    
    if correct_answers == len(questions):
        print("\nCongrats! Flag: HCS{f0R3n51k_1tu_m3n4rik}")

if __name__ == "__main__":
    main()