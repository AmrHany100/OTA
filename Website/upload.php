<?php
if (isset($_POST['submit']))
{
	/* Get Program File Info */
	$file        = $_FILES['file'];
	/* Name */
	$fileName    = $file['name'];
	/* Tmp Name */
	$fileTmpName = $file['tmp_name'];
	/* Error */
	$fileError   = $file['error'];
	/* Size */   
	$fileSize    = $file['size'];
	/* Extenation */
	$fileExt     = strtolower(end(explode('.',$fileName)));
	/* Allowed Extenation to Upload */
	$allowed     = array('hex', 'txt');
	if (in_array($fileExt,$allowed))
	{
		if ($fileError === 0)
		{
			if ($fileSize < 18000)
			{
				$fileDestination = "program.txt";
				move_uploaded_file($fileTmpName,$fileDestination);
				header("Location: done.html");
			}
			else
			{
				header("Location: error_size.html");
			}
		}
		else
		{
			header("Location: error_error.html");
		}
	}
	else
	{
		header("Location: error_type.html");
	}
}
?>