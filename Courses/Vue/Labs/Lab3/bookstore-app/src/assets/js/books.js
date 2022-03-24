let books = [
  {
    ISBN: 9789000307975,
    noOfPages: 28,
    stock: 12,
    title: "Vrienden voor het leven",
    author: "Maeve Binchy",
    category: "Alternate",
    summary:
      "Vrienden voor het leven is het verhaal van drie vriendinnen die op weg naar volwassenheid verwikkeld raken",
    image: "../images/bookcover0000014.jpg",
    price: 10
  },
  {
    ISBN: 9780552159722,
    noOfPages: 102,
    stock: 16,
    title: "Deception point",
    author: "Dan Brown",
    category: "history",
    summary:
      "When a new NASA satellite detects evidence of an astonishingly rare object buried deep in the Arctic",
    image: "../images/bookcover0000139.jpg",
    price: 9.99
  },
  {
    ISBN: 9789022558027,
    noOfPages: 86,
    stock: 13,
    title: "Magic staff",
    author: "Terry Brooks",
    category: "Autobiography",
    summary:
      "Vijf eeuwen geleden werd de wereld door een noodlottige demonenoorlog in de as gelegd. De overlevenden",
    image: "../images/bookcover0000214.jpg",
    price: 17.5
  },
  {
    ISBN: 9781841499789,
    noOfPages: 21,
    stock: 19,
    title: "Bloodfire Quest",
    author: "Terry Brooks",
    category: "Anthology",
    summary:
      "The adventure that started in Wards of Faerie takes a thrilling new turn, in the second",
    image: "../images/bookcover0000479.jpg",
    price: 24.5
  },
  {
    ISBN: 9781409117933,
    noOfPages: 42,
    stock: 20,
    title: "A Week in Winter",
    author: "Maeve Binchy",
    category: "Biography",
    summary:
      "Stoneybridge is full of holiday-makers in summer, its beaches are full of buckets and spades",
    image: "../images/bookcover0000603.jpg",
    price: 11.99
  },
  {
    ISBN: 9789460681387,
    noOfPages: 88,
    stock: 18,
    title: "Blue Curacao",
    author: "Linda van Rijn",
    category: "s",
    summary:
      "Als haar kersverse echtgenoot tijdens de huwelijksreis spoorloos verdwijnt, staat Hannah voor een raadsel. Hoe",
    image: "../images/bookcover0001169.jpg",
    price: 48.99
  },
  {
    ISBN: 9780751548525,
    noOfPages: 50,
    stock: 19,
    title: "Safe Haven",
    author: "Nicholas Sparks",
    category: "Classic",
    summary:
      "Love hurts. There is nothing as painful as heartbreak. But in order to learn to",
    image: "../images/bookcover0001205.jpg",
    price: 33.8
  },
  {
    ISBN: 9789023429258,
    noOfPages: 107,
    stock: 8,
    title: "De wereld volgens Garp",
    author: "John Irving",
    category: "Cookbook",
    summary:
      "De wereld volgens Garp is een zeldzaam komische, originele maar ook schokkende roman die John Irving",
    image: "../images/bookcover0001333.jpg",
    price: 19.9
  },
  {
    ISBN: 9789460680854,
    noOfPages: 63,
    stock: 17,
    title: "Winter Chalet",
    author: "Linda van Rijn",
    category: "Comic",
    summary:
      "Vier vriendinnen genieten van een skivakantie in Kirchberg. De moord op een van hen stelt iedereen",
    image: "../images/bookcover0001334.jpg",
    price: 15
  },
  {
    ISBN: 9789023464044,
    noOfPages: 77,
    stock: 19,
    title: "De Vliegeraar",
    author: "Khaled Hosseini",
    category: "Diary",
    summary:
      "Amir en Hassan zijn gevoed door dezelfde min en groeien samen op in de hoofdstad van Afghanistan",
    image: "../images/bookcover0001716.jpg",
    price: 6.99
  },
  {
    ISBN: 9789024529445,
    noOfPages: 87,
    stock: 18,
    title: "De delta deceptie",
    author: "Dan Brown",
    category: "Dictionary",
    summary:
      "Hij is terug... Een wetenschappelijke revolutie, een verbijsterende misleiding, een razendsnelle thriller! Onder",
    image: "../images/bookcover0001766.jpg",
    price: 14.95
  },
  {
    ISBN: 9789044309904,
    noOfPages: 27,
    stock: 6,
    title: "Hou je mond!",
    author: "Sophie Kinsella",
    category: "Crime",
    summary:
      "Emma heeft, zoals alle jonge vrouwen ter wereld, een paar geheimpjes. Voor haar ouders",
    image: "../images/bookcover0001921.jpg",
    price: 10
  },
  {
    ISBN: 9789023467786,
    noOfPages: 90,
    stock: 10,
    title: "In een mens",
    author: "John Irving",
    category: "Encyclopedia",
    summary:
      "In een mens is een meeslepende roman over verlangen, geheimhouding en seksuele identiteit. Een boek",
    image: "../images/bookcover0001995.jpg",
    price: 19.9
  },
  {
    ISBN: 9780751548556,
    noOfPages: 73,
    stock: 3,
    title: "The lucky one",
    author: "Nicholas Sparks",
    category: "Drama",
    summary:
      "Do you believe in lucky charms? While in Iraq, U.S. Marine Logan Thibault",
    image: "../images/bookcover0002745.jpg",
    price: 9.8
  },
  {
    ISBN: 9780751542974,
    noOfPages: 64,
    stock: 19,
    title: "Best of me",
    author: "Nicholas Sparks",
    category: "Guide",
    summary:
      "The new epic love story by the bestselling author of The Last Song and The Notebook.",
    image: "../images/bookcover0002853.jpg",
    price: 13.8
  },
  {
    ISBN: 9789000316090,
    noOfPages: 64,
    stock: 6,
    title: "Hotel aan zee",
    author: "Maeve Binchy",
    category: "Fairytale",
    summary:
      "In de zomer is het gezellig druk in het badplaatsje Stoneybridge. Overal slenteren vakantiegangers rond en",
    image: "../images/bookcover0003296.jpg",
    price: 14.99
  },
  {
    ISBN: 9789024561858,
    noOfPages: 51,
    stock: 12,
    title: "Inferno",
    author: "Dan Brown",
    category: "Fantasy",
    summary:
      "Inferno, de vierde Robert Langdon-thriller, speelt zich af in Italië. `Hoewel ik al",
    image: "../images/bookcover0003759.jpg",
    price: 17.49
  },
  {
    ISBN: 9789046113110,
    noOfPages: 36,
    stock: 15,
    title: "In het hart",
    author: "David Baldacci",
    category: "History",
    summary:
      "Dit is het aangrijpende verhaal van de twaalfjarige Louisa Mae Cardinal, die in New York woont",
    image: "../images/bookcover0003886.jpg",
    price: 5
  },
  {
    ISBN: 9781447229902,
    noOfPages: 34,
    stock: 14,
    title: "The Hit",
    author: "David Baldacci",
    category: "Historical",
    summary:
      "The trap is set. Failure is not an option. When government hit man Will Robie",
    image: "../images/bookcover0004103.jpg",
    price: 21.99
  },
  {
    ISBN: 9789044339482,
    noOfPages: 37,
    stock: 5,
    title: "De Tennisparty",
    author: "Sophie Kinsella",
    category: "fiction",
    summary:
      "Het tennisweekend is Patricks idee. Zijn nieuwe landhuis, gekocht met de bonussen van zijn baan",
    image: "../images/bookcover0004467.jpg",
    price: 18.5
  },
  {
    ISBN: 9780552778459,
    noOfPages: 65,
    stock: 18,
    title: "In One Person",
    author: "John Irving",
    category: "Humor",
    summary:
      "A compelling novel of desire, secrecy, and sexual identity, In One Person is a",
    image: "../images/bookcover0004949.jpg",
    price: 25
  },
  {
    ISBN: 9789400501157,
    noOfPages: 64,
    stock: 16,
    title: "De aanslag",
    author: "David Baldacci",
    category: "Horror",
    summary:
      "Will Robie is een van de besten in zijn vak, een huurmoordenaar die nooit twijfelt en",
    image: "../images/bookcover0006409.jpg",
    price: 19.99
  },
  {
    ISBN: 9789044339338,
    noOfPages: 52,
    stock: 16,
    title: "Mag ik je nummer even?",
    author: "Sophie Kinsella",
    category: "Journal",
    summary:
      "Poppy Wyatt is haar verlovingsring kwijt! Een antiek geval, al drie generaties in het bezit",
    image: "../images/bookcover0006794.jpg",
    price: 10
  },
  {
    ISBN: 9789022556627,
    noOfPages: 32,
    stock: 6,
    title: "Jarka Ruus",
    author: "Terry Brooks",
    category: "Mystery",
    summary:
      "Twintig jaar zijn voorbij gegaan sinds Grianne Ohmsford afstand deed van haar leven als de gevreesde Ilse",
    image: "../images/bookcover0008031.jpg",
    price: 18.95
  },
  {
    ISBN: 9789460680755,
    noOfPages: 60,
    stock: 13,
    title: "Last Minute",
    author: "Linda van Rijn",
    category: "Math",
    summary:
      "Op de lastminute-vakantie in Hurghada loopt Susan haar ex-vriend tegen het lijf. Liever had",
    image: "../images/bookcover0009421.jpg",
    price: 4.99
  },
  {
    ISBN: 9789023464143,
    noOfPages: 50,
    stock: 13,
    title: "Duizend schitterende zonnen",
    author: "Khaled Hosseini",
    category: "Textbook",
    summary:
      "De ongeschoolde Mariam is vijftien wanneer ze wordt uitgehuwelijkt aan de dertig jaar oudere schoenverkoper Rasheed in",
    image: "../images/bookcover0009976.jpg",
    price: 16.99
  },
  {
    ISBN: 9781408842423,
    noOfPages: 90,
    stock: 18,
    title: "And the Mountains Echoed",
    author: "Khaled Hosseini",
    category: "Satire",
    summary:
      "And the Mountains Echoed is a deeply moving story about how we love, how we take",
    image: "../images/bookcover0020515.jpg",
    price: 8.99
  },
];

export { books };