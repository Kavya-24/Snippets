object RetrofitClient {


    val url = "https://your-backend-url/"
    val TAG = RetrofitClient::class.java.simpleName


    private fun okhttpClient(context: Context): OkHttpClient {

        //The context is required if such interceptors/ authenticators are added
        return OkHttpClient.Builder()
            .followRedirects(false)
            .writeTimeout(20, TimeUnit.SECONDS)
            .build()
    }


    /**
     * Uses Moshi JSON Convertor
     */
    fun getInstanceofInterface(): RETURN_INTERFACE {

        val moshi = Moshi.Builder()
            .add(KotlinJsonAdapterFactory())
            .build()

        return Retrofit.Builder()
            .baseUrl(url)
            .addConverterFactory(MoshiConverterFactory.create(moshi))
            .addCallAdapterFactory(CoroutineCallAdapterFactory())
            .client(authClient())
            .build()
            .create(RETURN_INTERFACE::class.java)
    }


}