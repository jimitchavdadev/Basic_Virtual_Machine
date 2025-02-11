#include "lexer.h"

strings Lexer::lex(std::string s)
{
    strings strlst;
    char lexeme[256]; // Fixed-size buffer for token storage
    int i = 0, j = 0;
    State state = START;
    int len = s.length();
    int balance = 0;
    char beg_char = '"'; // Initialize or define appropriately
    char end_char = '"';

    while (i < len)
    {
        switch (state)
        {
        case START:
            if (my_issspace(s[i]))
            {
                state = SKIP;
            }
            else if (isgroup(s[i]))
            {
                if (s[i] == '"')
                {
                    lexeme[j++] = s[i];
                    i++;
                }
                state = READBLOCK;
            }
            else if (s[i] == '/' && s[i + 1] == '/')
            {
                i += 2;
                state = COMMENT;
            }
            else
            {
                state = READCHAR;
            }
            break;

        case READCHAR:
            if (my_issspace(s[i]))
            {
                state = DUMP;
            }
            else if (s[i] == '\\')
            {
                if (i + 1 < len)
                {
                    lexeme[j++] = s[i++];
                    lexeme[j++] = s[i++];
                }
            }
            else if (isgroup(s[i]))
            {
                if (s[i] == '"')
                {
                    lexeme[j++] = s[i++];
                }
                state = READBLOCK;
            }
            else if (isspecial(s[i]))
            {
                if (j == 0)
                {
                    lexeme[j++] = s[i++];
                }
                state = DUMP;
            }
            else if (s[i] == '/' && s[i + 1] == '/')
            {
                i += 2;
                state = COMMENT;
            }
            else
            {
                lexeme[j++] = s[i++];
            }
            break;

        case READBLOCK:
            if (s[i] == beg_char && s[i] != '"')
            {
                balance++;
                lexeme[j++] = s[i++];
            }
            else if (s[i] == end_char)
            {
                balance--;
                lexeme[j++] = s[i++];
                if (balance <= 0)
                {
                    state = DUMP;
                }
            }
            else if (end_char == '"' && s[i] == '\\')
            {
                if (i + 1 < len)
                {
                    lexeme[j++] = s[i++];
                    lexeme[j++] = s[i++];
                }
            }
            else
            {
                lexeme[j++] = s[i++];
            }
            break;

        case SKIP:
            while (i < len && my_issspace(s[i]))
            {
                i++;
            }
            state = READCHAR;
            break;

        case DUMP:
            if (j > 0)
            {
                lexeme[j] = '\0';
                strlst.push_back(lexeme);
                j = 0;
            }
            state = START;
            break;

        case COMMENT:
            while (i < len && s[i] != '\n')
            {
                i++;
            }
            state = READCHAR;
            break;

        case END:
            i = len;
            break;

        default:
            break;
        }

        // Ensure buffer doesn't overflow
        if (j >= 255)
        {
            lexeme[255] = '\0';
            strlst.push_back(lexeme);
            j = 0;
        }
    }

    if (j > 0)
    {
        lexeme[j] = '\0';
        strlst.push_back(lexeme);
    }

    return strlst;
}

// this function allows us to define what a space is
bool Lexer::my_issspace(char c)
{
    switch (c)
    {
    case '\n':
    case '\r':
    case '\t':
    case '\v':
    case '\f':
    case ' ':
        return true;
    default:
        return false;
    }
}

bool Lexer::isgroup(char c)
{
    beg_char = c;
    switch (c)
    {
    case '"':
        end_char = '"';
        return true;
    case '(':
        end_char = ')';
        return true;
    case ')':
        end_char = ')';
        return true;
    default:
        return false;
    }
}

bool Lexer::isspecial(char c)
{
    switch (c)
    {
    case '[':
    case ']':
        return true;
    default:
        return false;
    }
}