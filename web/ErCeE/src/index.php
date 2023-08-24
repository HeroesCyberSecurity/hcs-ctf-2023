<?php
$command = $_POST['cmd'] ?? ''; 

function sanitizeString($input) {
	$pattern = '/\|&/';
	$sanitized = preg_replace($pattern, '', $input);
	return $sanitized;
}

$sanitized = sanitizeString($command);

$output = system("ping " . $sanitized . "-c2");

echo "<pre>$output</pre>";
?>
<!DOCTYPE html>
<html>
<head>
    <title>Website Tester</title>
</head>
<body>
    <h1>Website Tester</h1>
    <form method="post">
        Command: <input type="text" name="cmd"><br>
        <input type="submit" value="Execute">
    </form>
</body>
</html>