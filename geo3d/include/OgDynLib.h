 #pragma once 




#define DYNLIB_HANDLE HINSTANCE
#define DYNLIB_LOAD( a ) LoadLibraryEx( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#define DYNLIB_GETSYM( a, b ) GetProcAddress( a, b )
#define DYNLIB_UNLOAD( a ) !FreeLibrary( a )



namespace Smart3dMap {

	class  DynLib
    {
	protected:
		string mName;
        /// Gets the last loading error
        string dynlibError(void);
    public:
        /** Default constructor - used by DynLibManager.
            @warning
                Do not call directly
        */
        DynLib( const string& name );

        /** Default destructor.
        */
        ~DynLib();

        /** Load the library
        */
        void load();
        /** Unload the library
        */
        void unload();
		/// Get the name of the library
		const string& getName(void) const { return mName; }

        /**
            Returns the address of the given symbol from the loaded library.
            @param
                strName The name of the symbol to search for
            @returns
                If the function succeeds, the returned value is a handle to
                the symbol.
            @par
                If the function fails, the returned value is <b>NULL</b>.

        */
        void* getSymbol( const string& strName ) const throw();

    protected:

        /// Handle to the loaded library.
        DYNLIB_HANDLE m_hInst;
    };
	/** @} */
	/** @} */

}
