
void keyInit()
{
    pinMode(PORT_0, INPUT);
    pinMode(PORT_1, INPUT);
    pinMode(PORT_2, INPUT);
}

enum EncoderValue ketGetEncoderValue()
{
    char p0, p1, p2;
    char value = 0;
    p0 = digitalRead(PORT_0);
    p1 = digitalRead(PORT_1);
    p2 = digitalRead(PORT_2);

    value = p2 * 100 + p1 * 10 + p0;
    switch (value)
    {
        case 0:
            return __000;
        case 1:
            return __001;
        case 10:
            return __010;
        case 11:
            return __011;
        case 100:
            return __100;
        case 101:
            return __101;
        case 110:
            return __110;
        case 111:
            return __111;
        default:
            return __111;
    }
}