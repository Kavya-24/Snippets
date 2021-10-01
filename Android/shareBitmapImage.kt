fun Activity.shareCacheDirBitmap(bitmap: Bitmap) {

    /**
     * Send a bitmap of the image that we want to share
     */

    try {
        
        val file = File("${this.cacheDir}/images.jpeg")

        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, FileOutputStream(file))

        val contentUri = FileProvider.getUriForFile(this, this.packageName + ".FileProvider", file)
       
        val shareIntent = Intent()
        shareIntent.action = Intent.ACTION_SEND
        shareIntent.putExtra(Intent.EXTRA_STREAM, contentUri)
        shareIntent.type = "image/*"        //All types of images
        this.startActivity(Intent.createChooser(shareIntent, "Share Image"))
        Log.e("Sharing", "Created share intent successfully")
    } catch (e: FileNotFoundException) {
        e.printStackTrace()
        Log.e("Sharing failed", e.toString())
    }
}

/**
 * Requirements in the manifest
 */


<provider
android:name="androidx.core.content.FileProvider"
android:authorities="com.example.appname.FileProvider"
android:exported="false"
android:grantUriPermissions="true">
<meta-data
    android:name="android.support.FILE_PROVIDER_PATHS"
    android:resource="@xml/file_paths" />
</provider> <!-- Content Provider for Recent Queries -->


/**
 * XML Paths
 * Useful in download providers as well
 */
<?xml file_paths>
<paths>

    <!-- Download path-->
    <root-path
        name="root"
        path="." />
    <cache-path
        name="images"
        path="." />
    <external-cache-path
        name="external-cache-path"
        path="." />
    <external-files-path
        name="external-files-path"
        path="." />
    <files-path
        name="files_path"
        path="." />

</paths>

/**
 * Use object with reference to activty/fragment ctx as activity.
 */