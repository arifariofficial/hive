// C0200 Reproduce the behavior of the function strcpy
char *ft_strcpy(char *dest, char *src) 
{
	int	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
// OR
char *ft_strcpy(char *dest, char *src) 
{
	char *original_destination = dest;

	while (*src != '\0') 
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return original_destination;
}

// C0201 Reproduce the behavior of the function strncpy 
char *ft_strncpy(char *dest, char *src, unsigned int n) 
{
	int	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
// OR
char *ft_strncpy(char *dest, char *src, unsigned int n) 
{
	char *original_destination = dest;
	unsigned int i = 0;

	while (i < n && *src != '\0') 
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	// if src is shorter than n, pad the rest with '\0'
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	
} 

/* C0202 Create a function that returns 1 if the string given as a parameter contains only alphabetical characters, and 0 if it contains any other character. It should return 1 if str is empty */

int ft_str_is_alpha(char *str) 
{
    if (*str == '\0') // Check if the string is empty
        return 1;

    while (*str) {
        if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))) {
            return 0; // Return 0 if a non-alphabetical character is found
        }
        str++;
    }
    return 1; // Return 1 if all characters are alphabetical
}

/* C0203 Create a function that returns 1 if the string given as a parameter contains only digits, and 0 if it contains any other character. It should return 1 if str is empty */

int ft_str_is_numeric(char *str) 
{
    if (*str == '\0') // Check if the string is empty
        return 1;

    while (*str) {
        if (!(*str >= '0' && *str <= '9')) {
            return 0; // Return 0 if a non-digit character is found
        }
        str++;
    }
    return 1; // Return 1 if all characters are digits
}

/* C0204 Create a function that returns 1 if the string given as a parameter contains only lowercase alphabetical characters, and 0 if it contains any other character. It should return 1 if str is empty */

int ft_str_is_lowercase(char *str) 
{
    if (*str == '\0') // Check if the string is empty
        return 1;

    while (*str) {
        if (!(*str >= 'a' && *str <= 'z')) {
            return 0; // Return 0 if a non-lowercase character is found
        }
        str++;
    }
    return 1; // Return 1 if all characters are lowercase
}

/* C0205 • Create a function that returns 1 if the string given as a parameter contains only uppercase alphabetical characters, and 0 if it contains any other character. It should return 1 if str is empty */

int ft_str_is_uppercase(char *str) 
{
    if (*str == '\0') // Check if the string is empty
        return 1;

    while (*str) {
        if (!(*str >= 'A' && *str <= 'Z')) {
            return 0; // Return 0 if a non-uppercase character is found
        }
        str++;
    }
    return 1; // Return 1 if all characters are uppercase
}

/* C0206 Create a function that returns 1 if the string given as a parameter contains only printable characters, and 0 if it contains any other character */
int ft_str_is_printable(char *str)
{
    int i = 0;

    // If the string is empty, return 1
    if (str[i] == '\0')
        return 1;

    // Iterate through the string
    while (str[i] != '\0')
    {
        // Check if the character is not printable
        if (str[i] < 32 || str[i] > 126)
            return 0;
        i++;
    }
    // If all characters are printable, return 1
    return 1;
}

/* C0207 Create a function that transforms every letter to uppercase */
char *ft_strupcase(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        // Check if the character is a lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Transform to uppercase by subtracting 32
            str[i] -= 32;
        }
        i++;
    }

    return str;
}

/* C0208 Create a function that transforms every letter to lowercase */
char *ft_strlowcase(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        // Check if the character is an uppercase letter
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // Transform to lowercase by adding 32
            str[i] += 32;
        }
        i++;
    }

    return str;
}

/* 
Create a function that capitalizes the first letter of each word and transforms all other letters to lowercase.
• A word is a string of alphanumeric characters.
• Here’s how it should be prototyped :
char *ft_strcapitalize(char *str);
• It should return str.
• For example:
salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
• Becomes:
Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
 */


int ft_is_alphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

char *ft_strcapitalize(char *str) {
    int i = 0;
    int new_word = 1; // 1 represents true, 0 represents false

    while (str[i] != '\0') {
        if (ft_is_alphanumeric(str[i])) {
            if (new_word && str[i] >= 'a' && str[i] <= 'z') {
                // Capitalize the first letter of a new word
                str[i] -= 32;
            } else if (!new_word && str[i] >= 'A' && str[i] <= 'Z') {
                // Convert uppercase letters to lowercase if not the start of a word
                str[i] += 32;
            }
            new_word = 0; // Inside a word
        } else {
            new_word = 1; // Non-alphanumeric character, reset for the next word
        }
        i++;
    }
    return str;
}


/* C0210 Reproduce the behavior of the function strlcpy (man strlcpy) */
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size) 
{
    unsigned int i = 0;
    unsigned int src_length = 0;

    // Calculate the length of the source string
    while (src[src_length] != '\0') {
        src_length++;
    }

    // If size is greater than 0, copy the string
    if (size > 0) {
        while (i < size - 1 && src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0'; // Null-terminate the destination string
    }

    return src_length; // Return the length of the source string
}

/* C0211 Create a function that displays a string of characters onscreen. If this string contains characters that aren’t printable, they’ll have to be displayed in the shape of hexadecimals (lowercase), preceeded by a "backslash".
For example : Coucou\ntu vas bien ?
The function should display : Coucou\0atu vas bien ? */

void ft_putstr_non_printable(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126) {
            // Printable characters
            ft_putchar(str[i]);
        } else {
            // Non-printable characters
            ft_putchar('\\');
            char hex[3]; // Store the hexadecimal representation
            hex[0] = "0123456789abcdef"[(unsigned char)str[i] / 16];
            hex[1] = "0123456789abcdef"[(unsigned char)str[i] % 16];
            hex[2] = '\0';
            ft_putchar(hex[0]);
            ft_putchar(hex[1]);
        }
        i++;
    }
}

/* C0212
• Create a function that displays the memory area onscreen.
• The display of this memory area should be split into three "columns" separated by a space:
	◦ The hexadecimal address of the first line’s first character followed by a ’:’.
	◦ The content in hexadecimal with a space each 2 characters and should be 	padded with spaces if needed (see the example below).
	◦ The content in printable characters.
• If a character is non-printable, it’ll be replaced by a dot.
• Each line should handle sixteen characters.
• If size is equal to 0, nothing should be displayed.
*/

// Function to print a single character
void ft_putchar(char c) {
    write(1, &c, 1);
}

// Function to print a hexadecimal value
void ft_puthex(unsigned char c) {
    char *hex = "0123456789abcdef";
    ft_putchar(hex[c / 16]);
    ft_putchar(hex[c % 16]);
}

// Function to display the memory area
void *ft_print_memory(void *addr, unsigned int size) {
    unsigned int i = 0;
    unsigned int j;
    unsigned char *memory = (unsigned char *)addr;

    while (i < size) {
        // Print the address
        unsigned long address = (unsigned long)&memory[i];
        for (int shift = (sizeof(address) * 2) - 1; shift >= 0; shift--) {
            ft_puthex((address >> (shift * 4)) & 0xF);
        }
        ft_putchar(':');
        ft_putchar(' ');

        // Print the content in hexadecimal
        for (j = 0; j < 16; j++) {
            if (i + j < size) {
                ft_puthex(memory[i + j]);
            } else {
                ft_putchar(' ');
                ft_putchar(' ');
            }
            if (j % 2 != 0)
                ft_putchar(' ');
        }

        // Print the content in printable characters
        for (j = 0; j < 16; j++) {
            if (i + j < size) {
                if (memory[i + j] >= 32 && memory[i + j] <= 126)
                    ft_putchar(memory[i + j]);
                else
                    ft_putchar('.');
            }
        }

        ft_putchar('\n');
        i += 16;
    }
    return addr;
}