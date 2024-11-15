import Menu from "../components/Menu";
import profilowe from "../img/profilowe.jpg";
import { useEffect, useRef } from "react";

export default function OMnie() {
  return (
    <>
      <Menu />
      <main className="o-mnie">
        <img src={profilowe} alt="Zdjęcie profilowe" />
        <div className="text">
          <h3>Wykształcenie:</h3>
          <p>
            Jestem absolwentem prawa na Uniwersytecie Jagiellońskim i aplikantem
            adwokackim w Krakowskiej Izbie Adwokackiej. Swoją pracę magisterską,
            tworzoną pod okiem prof. Mirosława Steca, obroniłem w Katedrze Prawa
            Gospodarczego.
          </p>
          <p>
            W 2024 roku ukończyłem studia podyplomowe na Uniwersytecie
            Jagiellońskim z zakresu prawa umów w obrocie konsumenckim i
            profesjonalnym, które prowadzone są przez uznanych prawników –
            wykładowców akademickich, adwokatów, sędziów Sądu Najwyższego oraz
            byłych sędziów Trybunału Konstytucyjnego.
          </p>
          <p>
            W 2023 roku uczestniczyłem w prowadzonych przez londyńskich
            adwokatów warsztatach – London ICCA Training on Advocacy Skills by
            Hampel Method, mających na celu doskonalenie umiejętności
            prawniczych.
          </p>
          <p>
            Ukończyłem także Akademię Prawa Gospodarczego prowadzoną przez znaną
            kancelarię prawną SPCG - T.&nbsp;Studnicki, K.&nbsp;Płeszka,
            Z.&nbsp;Ćwiąkalski, J.&nbsp;Górski sp.k., w której odbywałem również
            praktyki.
          </p>
          <h3>Doświadczenie:</h3>
          <p>
            Specjalizuję się w prawie cywilnym, w tym w szczególności prawie
            bankowym i konsumenckim. W swojej dotychczasowej karierze zawodowej
            sporządziłem setki pism procesowych i opinii prawnych w zakresie:
          </p>
          <ul>
            <li>
              stwierdzenia bezskuteczności niedozwolonych postanowień zawartych
              w umowach pożyczkowych;
            </li>
            <li>
              odzyskiwania zwrotu części prowizji dla konsumenta za wcześniejszą
              spłatę kredytu;
            </li>
            <li>unieważniania tzw. kredytów frankowych;</li>
          </ul>

          <p>
            <b>Doradzam przedsiębiorcom</b> – spółkom kapitałowym i osobowym,
            jak również jednoosobowym działalnościom gospodarczym, głównie w
            zakresie:
          </p>
          <ul>
            <li>
              sporządzania regulaminów i polityki prywatności (RODO, pliki
              cookies);
            </li>
            <li>
              analizy umów z zakresu finansowania inwestycji, m.in. umów
              kredytowych, umów cesji wierzytelności;
            </li>
            <li>
              prowadzenia działań przedsądowych i sądowych mających na celu
              odzyskanie środków od dłużników;
            </li>
            <li>zakładania działalności gospodarczej w CEIDG;</li>
            <li>
              zakładania spółki lub zmiany umowy spółki za pośrednictwem portalu
              S24;
            </li>
          </ul>
          <p>
            <b>Doradzam osobom fizycznym</b> – posiadam szerokie doświadczenie w
            zakresie spraw spadkowych, działowych, lokatorskich. Wielokrotnie
            zajmowałem się sprawami dotyczącymi:
          </p>
          <ul>
            <li>stwierdzenia nabycia spadku;</li>
            <li>działu spadku i zniesienia współwłasności;</li>
            <li>zasiedzenia nieruchomości;</li>
            <li>opiniowania i sporządzania umów najmu lokalu;</li>
          </ul>
          <h3>Pozostałe informacje o mnie:</h3>
          <ul>
            <li>
              Stypendysta Rektora Uniwersytetu Jagiellońskiego dla najlepszych
              studentów
            </li>
            <li>
              Laureat I miejsca w Ogólnopolskim Konkursie Forum Rynków
              Finansowych: Inwestycje, Bankowość &&nbsp;FinTech 2020
            </li>
            <li>Finalista konkursu podatkowego KPMG Tax’n’You 2022</li>
          </ul>
        </div>
      </main>
    </>
  );
}
