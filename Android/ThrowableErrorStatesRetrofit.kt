fun returnStateMessageForThrowable(throwable: Throwable): String {
    var message: String = ""


    when (throwable) {
        is IOException -> {
            message = ApplicationUtil.getContext()
                .getString(R.string.error_please_check_internet)
        }
        is TimeoutException -> {
            message = ApplicationUtil.getContext()
                .getString(R.string.error_request_timed_out)
        }
        is HttpException -> {
            val httpException = throwable
            val response = httpException.response()?.errorBody()?.string()

            message = response!!
        }
        else -> {
            message = ApplicationUtil.getContext()
                .getString(R.string.error_something_went_wrong)
        }
    }

    return message
}
