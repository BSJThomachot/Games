Dim WshShell
Set WshShell = WScript.CreateObject("WScript.Shell")
''WScript.Echo WshShell.CurrentDirectory

Set FSO = CreateObject("Scripting.FileSystemObject")
ShowSubfolders FSO.GetFolder(WshShell.CurrentDirectory)
Sub ShowSubFolders(Folder)
	For Each File in Folder.Files
		If InStr(File.Path, ".sdf") or InStr(File.Path, ".suo") or InStr(File.Path, ".user") Then
			FSO.DeleteFile File.Path
		End If
	Next
    For Each Subfolder in Folder.SubFolders
        ''Wscript.Echo Subfolder.Path
		If InStr(SubFolder.Path, "Debug") <> 0 or InStr(SubFolder.Path, "Release") or InStr(SubFolder.Path, "ipch") Then
			''Wscript.Echo Subfolder.Path
			FSO.DeleteFolder SubFolder.Path 
		Else
			ShowSubFolders Subfolder
		End If
    Next
End Sub