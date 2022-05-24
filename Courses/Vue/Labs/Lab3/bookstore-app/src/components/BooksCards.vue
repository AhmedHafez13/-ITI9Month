<template>
  <div>
    <div class="container">
      <!-- [START] Books cards -->
      <div class="d-flex justify-content-around flex-wrap">
        <div
          v-for="book in books"
          :key="book.ISBN"
          class="card book-card m-3"
          style="max-width: 16rem"
        >
          <BookCard :book="book" />
        </div>
      </div>
      <!-- [END] Books cards -->
    </div>
  </div>
</template>


<script>
import BookCard from "../components/BookCard.vue";

import { store } from "../store.js";

let data = () => ({
  books: store.books,
});

export default {
  data,
  components: {
    BookCard,
  },
};
</script>
